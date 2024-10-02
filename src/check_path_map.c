/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:33:29 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 09:20:50 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Frees memory allocated for the map copy
void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

// Recursively fills the map from the current point
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if ((tab[cur.y][cur.x] == 'P') || (tab[cur.y][cur.x] == 'C')
		|| (tab[cur.y][cur.x] == '0'))
	{
		tab[cur.y][cur.x] = '0';
	}
	if ((cur.y < 0) || (cur.y >= size.y) || (cur.x < 0)
		|| (cur.x >= size.x) || (tab[cur.y][cur.x] != to_fill))
	{
		return ;
	}
	tab[cur.y][cur.x] = 'V';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

// Checks if all important points (e.g., exits, collectibles) are reachable
int	check_map_copy(char **map_copy, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->m.rows)
	{
		j = 0;
		while (j < game->m.cols)
		{
			if (map_copy[i][j] == 'E' || map_copy[i][j] == 'C')
			{
				if (map_copy[i - 1][j] != 'V' && map_copy[i + 1][j] != 'V'
					&& map_copy[i][j + 1] != 'V' && map_copy[i][j - 1] != 'V')
				{
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

// Finds the player's coordinates ('P') on the map
void	fill_cur(t_point *cur, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->m.map[i])
	{
		j = 0;
		while (game->m.map[i][j])
		{
			if (game->m.map[i][j] == 'P')
			{
				cur->y = i;
				cur->x = j;
			}
			j++;
		}
		i++;
	}
}

// Checks if the player's path reaches necessary points and is valid
int	check_path_map(t_game *game)
{
	char	**map_copy;
	t_point	size;
	t_point	cur;

	fill_cur(&cur, game);
	map_copy = copy_map(game);
	map_copy[cur.y][cur.x] = '0';
	size.x = game->m.cols;
	size.y = game->m.rows;
	fill(map_copy, size, cur, map_copy[cur.y][cur.x]);
	if (!check_map_copy(map_copy, game))
	{
		free_map_copy(map_copy);
		return (0);
	}
	free_map_copy(map_copy);
	return (1);
}

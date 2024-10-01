/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:51:51 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/01 16:38:48 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*init_strut(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->m.fd = 0;
	game->m.rows = 0;
	game->m.cols = 0;
	game->m.map = NULL;
	game->p.count_p = 0;
	game->p.count_e = 0;
	game->p.count_c = 0;
	game->p.count_move = 0;
	game->m.buffer = NULL;
	game->mlx_ptr = NULL;
	game->mlx_ptr = NULL;
	game->img_0 = NULL;
	game->img_1 = NULL;
	game->img_p = NULL;
	game->img_c = NULL;
	game->img_e = NULL;
	game->p.x = 0;
	game->p.y = 0;
	return (game);
}

void	ft_free_struct(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (game->m.map != NULL)
	{
		while (game->m.map[i])
		{
			free(game->m.map[i]);
			i++;
		}
		free(game->m.map);
	}
	free(game);
}

void	ft_print_str_nbr(char *str, int nbr, char c)
{
	ft_putstr_fd(str, 1);
	ft_putnbr_fd(nbr, 1);
	ft_putchar_fd(c, 1);
}
char	**copy_map(t_game *game)
{
	int	i;
	int j;
	char **map_cpy;

	map_cpy = malloc(sizeof(char *) * (game->m.rows + 1));
	i = 0;
	while (i < game->m.rows)
	{
		map_cpy[i] = malloc(sizeof(char) * (game->m.cols + 1));
		j = 0;
		while (j < game->m.cols)
		{
			map_cpy[i][j] = game->m.map[i][j];
			j++;
		}
		map_cpy[i][j] = '\0';
		i++;
	}
	map_cpy[i] = '\0';
	return (map_cpy);
}
void	count_elements(t_game *game)
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
				game->p.count_p++;
			else if (game->m.map[i][j] == 'E')
				game->p.count_e++;
			else if (game->m.map[i][j] == 'C')
				game->p.count_c++;
			j++;
		}
		i++;
	}
}

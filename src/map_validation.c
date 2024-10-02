/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:08:52 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 09:30:08 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Checks if the file has a ".ber" extension
int	check_extension(const char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i)
	{
		if (str[i] == 'r' && str[i - 1] == 'e')
		{
			if (str[i - 2] == 'b' && str[i - 3] == '.')
				if (str[i - 4] != '\0')
					return (1);
		}
		i--;
	}
	return (0);
}

// Validates that the map is rectangular
int	check_map_shape(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	calculate_map_dimensions(game);
	while (game->m.map[i])
	{
		j = 0;
		while (game->m.map[i][j])
			j++;
		if (game->m.cols != j)
			return (0);
		i++;
	}
	return (1);
}

// Checks if the map is surrounded by walls ('1')
int	check_wall_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->m.map[0][i])
	{
		if (game->m.map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->m.rows)
	{
		if (game->m.map[i][0] != '1' ||
				game->m.map[i][game->m.cols - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (game->m.map[game->m.rows - 1][i])
	{
		if (game->m.map[game->m.rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// Checks for valid player, exit, and collectible counts
void	check_map_elements(t_game *game)
{
	count_elements(game);
	if (game->p.count_p != 1)
	{
		ft_free_struct(game);
		ft_error_exit("Error: \nInvalid player count.\n");
	}
	if (game->p.count_e != 1)
	{
		ft_free_struct(game);
		ft_error_exit("Error: \nInvalid exit count.\n");
	}
	if (game->p.count_c < 1)
	{
		ft_free_struct(game);
		ft_error_exit("Error: \nInvalid collectible count.\n");
	}
}

// Validates map characters ('1', '0', 'C', 'P', 'E')
int	check_map_elements_invalid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->m.map[i])
	{
		j = 0;
		while (game->m.map[i][j])
		{
			if ((game->m.map[i][j] != '1') && (game->m.map[i][j] != 'C')
					&& (game->m.map[i][j] != 'P') &&
					(game->m.map[i][j] != 'E')
					&& (game->m.map[i][j] != '0'))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

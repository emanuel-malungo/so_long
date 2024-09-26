/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 07:49:28 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:54:33 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	position_player(t_game *game)
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
				game->p.x = i;
				game->p.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	calculate_map_dimensions(t_game *game)
{
	game->m.cols = 0;
	game->m.rows = 0;
	while (game->m.map[0][game->m.cols])
		game->m.cols++;
	while (game->m.map[game->m.rows])
		game->m.rows++;
}

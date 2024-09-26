/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:49:09 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:53:40 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_map_dimensions(t_game *game)
{
	if ((game->m.cols * 50) > 1920 || (game->m.rows * 50) > 1080)
		return (0);
	return (1);
}

int	check_collection_right_left(t_game *game, int i, int j, char c)
{
	if (c == 'L')
	{
		if (game->m.map[i][j - 1] == 'E')
		{
			if (game->m.count_c == 0)
				on_destroy(game);
			else
				return (0);
		}
	}
	if (c == 'R')
	{
		if (game->m.map[i][j + 1] == 'E')
		{
			if (game->m.count_c == 0)
				on_destroy(game);
			else
				return (0);
		}
	}
	return (1);
}

int	check_collection_up_down(t_game *game, int i, int j, char c)
{
	if (c == 'U')
	{
		if (game->m.map[i - 1][j] == 'E')
		{
			if (game->m.count_c == 0)
				on_destroy(game);
			else
				return (0);
		}
	}
	if (c == 'D')
	{
		if (game->m.map[i + 1][j] == 'E')
		{
			if (game->m.count_c == 0)
				on_destroy(game);
			else
				return (0);
		}
	}
	return (1);
}

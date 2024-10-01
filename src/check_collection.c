/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:49:09 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/30 11:38:31 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_collection_right(t_game *game, int i, int j)
{
	if (game->m.map[i][j + 1] == 'E')
	{
		if (game->p.count_c == 0)
		{
			ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
			on_destroy(game);
		}
		else
			return (0);
	}
	return (1);
}

int	check_collection_left(t_game *game, int i, int j)
{
	if (game->m.map[i][j - 1] == 'E')
	{
		if (game->p.count_c == 0)
		{
			ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
			on_destroy(game);
		}
		else
			return (0);
	}
	return (1);
}

int	check_collection_up(t_game *game, int i, int j)
{
	if (game->m.map[i - 1][j] == 'E')
	{
		if (game->p.count_c == 0)
		{
			ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
			on_destroy(game);
		}
		else
			return (0);
	}
	return (1);
}

int	check_collection_down(t_game *game, int i, int j)
{
	if (game->m.map[i + 1][j] == 'E')
	{
		if (game->p.count_c == 0)
		{
			ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
			on_destroy(game);
		}
		else
			return (0);
	}
	return (1);
}

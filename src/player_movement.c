/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:08 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 09:31:55 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Moves the player up if the next position is valid
void	move_up(t_game *game)
{
	int	i;
	int	j;

	position_player(game);
	i = game->p.x;
	j = game->p.y;
	if (i > 0 && game->m.map[i - 1][j] != '1')
	{
		if (game->m.map[i - 1][j] == 'C')
			game->p.count_c--;
		if (!check_collection_up(game, i, j))
			return ;
		game->m.map[i][j] = '0';
		game->p.x--;
		game->m.map[game->p.x][game->p.y] = 'P';
		ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
		draw_map(game);
	}
}

// Moves the player down if the next position is valid
void	move_down(t_game *game)
{
	int	i;
	int	j;

	position_player(game);
	i = game->p.x;
	j = game->p.y;
	if (i > 0 && game->m.map[i + 1][j] != '1')
	{
		if (game->m.map[i + 1][j] == 'C')
			game->p.count_c--;
		if (!check_collection_down(game, i, j))
			return ;
		game->m.map[i][j] = '0';
		game->p.x++;
		game->m.map[game->p.x][game->p.y] = 'P';
		ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
		draw_map(game);
	}
}

// Moves the player right if the next position is valid
void	move_right(t_game *game)
{
	int	i;
	int	j;

	position_player(game);
	i = game->p.x;
	j = game->p.y;
	if (i > 0 && game->m.map[i][j + 1] != '1')
	{
		if (game->m.map[i][j + 1] == 'C')
			game->p.count_c--;
		if (!check_collection_right(game, i, j))
			return ;
		game->m.map[i][j] = '0';
		game->p.y++;
		game->m.map[game->p.x][game->p.y] = 'P';
		ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
		draw_map(game);
	}
}

// Moves the player left if the next position is valid
void	move_left(t_game *game)
{
	int	i;
	int	j;

	position_player(game);
	i = game->p.x;
	j = game->p.y;
	if (i > 0 && game->m.map[i][j - 1] != '1')
	{
		if (game->m.map[i][j - 1] == 'C')
			game->p.count_c--;
		if (!check_collection_left(game, i, j))
			return ;
		game->m.map[i][j] = '0';
		game->p.y--;
		game->m.map[game->p.x][game->p.y] = 'P';
		ft_print_str_nbr("Movements: ", game->p.count_move++, '\n');
		draw_map(game);
	}
}

// Finds and updates the player's current position in the map
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

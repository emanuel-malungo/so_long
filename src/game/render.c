/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:54:08 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:53:45 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
		{
			game->m.count_c--;
			printf("Item coletado! Restam: %d\n", game->m.count_c);
		}
		if (!check_collection_up_down(game, i, j, 'U'))
			return ;
		game->m.map[i][j] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_0, j * 50, i * 50);
		game->p.x--;
		game->m.map[game->p.x][game->p.y] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_p, game->p.y * 50, game->p.x * 50);
		game->m.count_move++;
		printf("Movimento: %d\n", game->m.count_move);
	}
}

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
		{
			game->m.count_c--;
			printf("Item coletado! Restam: %d\n", game->m.count_c);
		}
		if (!check_collection_up_down(game, i, j, 'D'))
			return ;
		game->m.map[i][j] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_0, j * 50, i * 50);
		game->p.x++;
		game->m.map[game->p.x][game->p.y] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_p,
			game->p.y * 50, game->p.x * 50);
		game->m.count_move++;
		printf("Movimento: %d\n", game->m.count_move);
	}
}

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
		{
			game->m.count_c--;
			printf("Item coletado! Restam: %d\n", game->m.count_c);
		}
		if (!check_collection_right_left(game, i, j, 'R'))
			return ;
		game->m.map[i][j] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_0, j * 50, i * 50);
		game->p.y++;
		game->m.map[game->p.x][game->p.y] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_p, game->p.y * 50, game->p.x * 50);
		game->m.count_move++;
		printf("Movimento: %d\n", game->m.count_move);
	}
}

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
		{
			game->m.count_c--;
			printf("Item coletado! Restam: %d\n", game->m.count_c);
		}
		if (!check_collection_right_left(game, i, j, 'L'))
			return ;
		game->m.map[i][j] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_0, j * 50, i * 50);
		game->p.y--;
		game->m.map[game->p.x][game->p.y] = 'P';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_p, game->p.y * 50, game->p.x * 50);
		game->m.count_move++;
		printf("Movimento: %d\n", game->m.count_move);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:13 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:54:18 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == 65307)
		on_destroy(game);
	if (keysym == 119)
		move_up(game);
	if (keysym == 97)
		move_left(game);
	if (keysym == 115)
		move_down(game);
	if (keysym == 100)
		move_right(game);
	if (keysym == 65363)
		move_right(game);
	if (keysym == 65361)
		move_left(game);
	if (keysym == 65364)
		move_down(game);
	if (keysym == 65362)
		move_up(game);
	return (0);
}

int	on_destroy(t_game *game)
{
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
	close(game->m.fd);
	ft_free_struct(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_game(t_game *game, char *path_name)
{
	game->m.fd = open(path_name, O_RDONLY);
	if (game->m.fd == -1)
	{
		free(game->m.buffer);
		ft_free_struct(game);
		ft_putstr_fd("Error: Cannot open file.\n", 2);
		exit (EXIT_FAILURE);
	}
	get_parse_map(game);
	validate_map(game);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr)
	{
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->m.cols * 50,
				game->m.rows * 50, "SO_LONG");
		mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &on_keypress, game);
		mlx_hook(game->win_ptr, DestroyNotify,
			StructureNotifyMask, &on_destroy, game);
		mlx_loop_hook(game->mlx_ptr, &draw_map, game);
		mlx_loop(game->mlx_ptr);
	}
	free(game->mlx_ptr);
	close(game->m.fd);
	ft_free_struct(game);
}

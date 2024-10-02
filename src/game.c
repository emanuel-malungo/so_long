/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:13 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 09:25:09 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Destroys all loaded images in the game
void	destroy_all_imagens(t_game *game)
{
	if (game->img_1 != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_1);
	if (game->img_0 != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_0);
	if (game->img_e != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_e);
	if (game->img_c != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_c);
	if (game->img_p != NULL)
		mlx_destroy_image(game->mlx_ptr, game->img_p);
}

// Destroys game resources, closes the window, and exits the game
int	on_destroy(t_game *game)
{
	destroy_all_imagens(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	close(game->m.fd);
	ft_free_struct(game);
	exit(EXIT_SUCCESS);
	return (0);
}

// Handles keypress events to move the player or exit the game
int	on_keypress(int keysym, t_game *game)
{
	if (keysym == 65307)
		on_destroy(game);
	if (keysym == 'w' || keysym == 65362)
		move_up(game);
	if (keysym == 97 || keysym == 65361)
		move_left(game);
	if (keysym == 115 || keysym == 65364)
		move_down(game);
	if (keysym == 100 || keysym == 65363)
		move_right(game);
	return (0);
}

// Opens a file, parses the map, and validates its elements
void	open_file(t_game *game, char *path_name)
{
	game->m.img_width = 0;
	game->m.img_height = 0;
	game->m.fd = open(path_name, O_RDONLY);
	if (game->m.fd == -1)
	{
		free(game->m.buffer);
		ft_free_struct(game);
		ft_putstr_fd("Error: Cannot open file.\n", 2);
		exit (EXIT_FAILURE);
	}
	get_parse_map(game);
	check_map_elements(game);
	map_validation(game);
}

// Initializes the game, loads textures, creates window, starts loop
void	init_game(t_game *game, char *path_name)
{
	open_file(game, path_name);
	game->mlx_ptr = mlx_init();
	if (!lead_texture(game, game->m.img_width, game->m.img_height))
	{
		ft_putstr_fd("Error: Could not load image.\n", 2);
		exit (EXIT_FAILURE);
	}
	if (game->mlx_ptr)
	{
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->m.cols * 50,
				game->m.rows * 50, "SO_LONG");
		mlx_key_hook(game->win_ptr, &on_keypress, game);
		mlx_hook(game->win_ptr, 17, (1L << 17), on_destroy, game);
		draw_map(game);
		mlx_loop(game->mlx_ptr);
	}
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	ft_free_struct(game);
	exit(EXIT_FAILURE);
}

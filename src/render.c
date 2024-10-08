/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 06:47:09 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 10:41:57 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Loads textures for different map elements
int	lead_texture(t_game *game, int img_width, int img_height)
{
	game->img_0 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./texture/IMG_0.xpm", &img_width,
			&img_height);
	game->img_1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./texture/IMG_1.xpm", &img_width, &img_height);
	game->img_p = mlx_xpm_file_to_image(game->mlx_ptr,
			"./texture/IMG_P3.xpm", &img_width, &img_height);
	game->img_c = mlx_xpm_file_to_image(game->mlx_ptr,
			"./texture/IMG_C3.xpm", &img_width, &img_height);
	game->img_e = mlx_xpm_file_to_image(game->mlx_ptr,
			"./texture/IMG_E1.xpm", &img_width, &img_height);
	if (!game->img_0 || !game->img_1 || !game->img_p
		|| !game->img_c || !game->img_e)
		return (0);
	return (1);
}

// Draws the corresponding image for each map tile
void	fill_map(t_game *game, int x, int y)
{
	if (game->m.map[x][y] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_1, y * 50, x * 50);
	else if (game->m.map[x][y] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_0, y * 50, x * 50);
	else if (game->m.map[x][y] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_c, y * 50, x * 50);
	else if (game->m.map[x][y] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_p, y * 50, x * 50);
	else if (game->m.map[x][y] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_e, y * 50, x * 50);
}

// Iterates through the map and draws all tiles
int	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->m.map[x])
	{
		y = 0;
		while (game->m.map[x][y])
		{
			fill_map(game, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:59:46 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 08:56:52 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	char	*buffer;
	char	**map;
	int		fd;
	int		cols;
	int		rows;
	int		img_width;
	int		img_height;
}		t_map;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_play
{
	int	x;
	int	y;
	int	count_p;
	int	count_e;
	int	count_c;
	int	count_move;
}	t_play;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_0;
	void	*img_1;
	void	*img_e;
	void	*img_c;
	void	*img_p;
	t_map	m;
	t_play	p;
}	t_game;

// ./src/map_validation.c
int		check_wall_map(t_game *game);
int		check_map_shape(t_game *game);
void	check_map_elements(t_game *game);
int		check_extension(const char *str);
int		check_map_elements_invalid(t_game *game);

// ./src/input_validation.c
void	ft_error_exit(char *str);
void	check_buffer(t_game *game);
void	map_validation(t_game *game);
void	input_validation(int argc, char **argv);

// ./src/parse_game.c
void	*read_map(t_game *game);
void	get_parse_map(t_game *game);
void	calculate_map_dimensions(t_game *game);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);
void	*read_and_resize_buffer(t_game *game, size_t *t_read, size_t *buffer_s);

// ./src/game.c
int		on_destroy(t_game *game);
void	destroy_all_imagens(t_game *game);
int		on_keypress(int keysym, t_game *game);
void	open_file(t_game *game, char *path_name);
void	init_game(t_game *game, char *path_name);

// ./src/player_movement.c
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	position_player(t_game *game);

// ./src/check_collection.c
int		check_collection_up(t_game *game, int i, int j);
int		check_collection_down(t_game *game, int i, int j);
int		check_collection_left(t_game *game, int i, int j);
int		check_collection_right(t_game *game, int i, int j);

// ./src/check_path_map.c
int		check_path_map(t_game *game);
void	free_map_copy(char **map_copy);
int		check_map_copy(char **map_copy, t_game *game);
void	fill(char **tab, t_point size, t_point cur, char to_fill);

// ./src/reder.c
int		draw_map(t_game *game);
void	fill_map(t_game *game, int x, int y);
int		lead_texture(t_game *game, int img_width, int img_height);

// ./src/utils.c
t_game	*init_strut(void);
char	**copy_map(t_game *game);
void	count_elements(t_game *game);
void	ft_free_struct(t_game *game);
void	ft_print_str_nbr(char *str, int nbr, char c);

#endif

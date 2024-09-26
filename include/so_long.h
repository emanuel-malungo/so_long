/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:59:46 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:55:13 by emalungo         ###   ########.fr       */
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
# include <X11/keysym.h>
# include <X11/X.h> 

typedef struct t_map
{
	char	*buffer;
	char	**map;
	int		fd;
	int		rows;
	int		cols;
	int		count_p;
	int		count_e;
	int		count_c;
	int		count_move;
}		t_map;

typedef struct t_play
{
	int	x;
	int	y;
}	t_play;

typedef struct t_game
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

// ./src/utils/memory.c
t_game	*init_strut(void);
void	ft_free_struct(t_game *game);
void	*ft_realloc(void *ptr, size_t new_size, size_t old_size);

// ./src/utils/error_checking.c
int		check_wall_map(t_game *game);
int		check_map_shape(t_game *game);
int		check_map_elements(t_game *game);
int		check_extension(const char *str);
int		check_map_elements_invalid(t_game *game);

// ./src/utils/input_validation.c
void	ft_error_exit(char *str);
void	validate_map(t_game *game);
void	input_valid(int argc, char **argv);

// ./src/game/parse_game.c
void	*read_map(t_game *game);
void	get_parse_map(t_game *game);
void	*read_and_resize_buffer(t_game *game, size_t *t_read, size_t *buffer_s);

// ./src/game/game.c
int		on_destroy(t_game *game);
int		on_keypress(int keysym, t_game *game);
void	init_game(t_game *game, char *path_name);

// ./src/game/render.c
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

// ./src/game/check_game.c
int		check_map_dimensions(t_game *game);
int		check_collection_up_down(t_game *game, int i, int j, char c);
int		check_collection_right_left(t_game *game, int i, int j, char c);

int		draw_map(t_game *game);

// ./src/utils/utils.c
void	position_player(t_game *game);
void	calculate_map_dimensions(t_game *game);

#endif

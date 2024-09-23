/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:59:46 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/23 12:52:24 by emalungo         ###   ########.fr       */
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
}		t_map;

typedef struct t_game
{
	void *mlx_ptr;
	void *win_ptr;
	t_map	m;
}	t_game;

// ./src/utils/memory.c
t_game	*init_strut(void);
void	ft_free_struct(t_game *game);
void	*ft_realloc(void* ptr, size_t new_size, size_t old_size);

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
void	get_parse_map(t_game *game);
void    calculate_map_dimensions(t_game *game);

// ./src/game/game.c
void	init_game(t_game *game, char *path_name);

#endif

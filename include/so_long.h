/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:05:11 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 14:59:46 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct t_game
{
	int		fd;
	char	*buffer;
	char	**map;
}			t_game;

// ./src/utils/error_handling.c
void	ft_error_exit(char *str);
int		check_extension(char *str);

// ./src/utils/string_utils.c
void	ft_printf(char	*format, ...);

// ./src/map/parse_game.c
void	get_parse_map(t_game **game);

// ./src/utils/memory.c
t_game	*init_game(void);
void	ft_free_split(char **split);
void	free_game(t_game *game);

#endif

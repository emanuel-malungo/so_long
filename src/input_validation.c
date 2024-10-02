/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:22:26 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/02 14:08:39 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Prints error message and exits the program
void	ft_error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

// Validates input arguments
void	input_validation(int argc, char **argv)
{
	if (argc != 2)
		ft_error_exit("Error:\n Usage: ./so_long <map_file>\n");
	if (!check_extension(argv[1]))
		ft_error_exit("Error:\n Invalid file extension.\n");
}

// Validates the map structure, walls, characters, and path
void	map_validation(t_game *game)
{
	if (!check_map_shape(game))
	{
		ft_free_struct(game);
		ft_error_exit("Error:\n Map must be rectangular.\n");
	}
	if (!check_wall_map(game))
	{
		ft_free_struct(game);
		ft_error_exit("Error:\n Invalid walls.\n");
	}
	if (!check_map_elements_invalid(game))
	{
		ft_free_struct(game);
		ft_error_exit("Error:\n Invalid characters in map.\n");
	}
	if (!check_path_map(game))
	{
		ft_free_struct(game);
		ft_error_exit("Error:\n Invalid map path.\n");
	}
}

// Checks for invalid newlines in the map buffer
void	check_buffer(t_game *game)
{
	int	i;

	i = 0;
	while (game->m.buffer[i])
	{
		if ((game->m.buffer[i] == '\n') && (game->m.buffer[i + 1])
			&& (game->m.buffer[i + 1] == '\n'))
		{
			free(game->m.buffer);
			ft_free_struct(game);
			ft_error_exit("Error:\n map cannot have two newlines in a row\n");
		}
		i++;
	}
	if (i > 0 && game->m.buffer[i - 1] == '\n')
	{
		free(game->m.buffer);
		ft_free_struct(game);
		ft_error_exit("Error:\n map cannot end with a newline\n");
	}
}

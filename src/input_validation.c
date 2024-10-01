/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:22:26 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/01 16:43:56 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
void	input_validation(int argc, char **argv)
{
	if (argc != 2)
		ft_error_exit("Usage: ./so_long <map_file>\n");
	if (!check_extension(argv[1]))
		ft_error_exit("Error: Invalid file extension.\n");
}
void	map_validation(t_game *game)
{
	if (!check_map_shape(game))
	{
		ft_free_struct(game);
		ft_error_exit("Map must be rectangular.\n");
	}
	if (!check_wall_map(game))
	{
		ft_free_struct(game);
		ft_error_exit("Invalid walls.\n");
	}
	if (!check_map_elements_invalid(game))
	{
		ft_free_struct(game);
		ft_error_exit("Invalid characters in map.\n");
	}
	if (!check_path_map(game))
	{
		ft_free_struct(game);
		ft_error_exit("Invalid map path.\n");
	}
}
void	check_buffer(t_game *game)
{
	int	i;

	i = 0;
	if (game->m.buffer[0] == '\n')
	{
		free(game->m.buffer);
		ft_free_struct(game);
		ft_error_exit("Error: map cannot start with a newline\n");
	}
	while (game->m.buffer[i])
	{
		if (game->m.buffer[i] == '\n' && game->m.buffer[i + 1] && game->m.buffer[i + 1] == '\n')
		{
			free(game->m.buffer);
			ft_free_struct(game);
			ft_error_exit("Error: map cannot have two newlines in a row\n");
		}
		i++;
	}
	if (i > 0 && game->m.buffer[i - 1] == '\n')
	{
		free(game->m.buffer);
		ft_free_struct(game);
		ft_error_exit("Error: map cannot end with a newline\n");
	}
}


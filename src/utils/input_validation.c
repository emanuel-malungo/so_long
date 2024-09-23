/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:22:26 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/23 12:15:15 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	input_valid(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!check_extension(argv[1]))
	{
		ft_putstr_fd("Error: Invalid file extension.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	validate_map(t_game *game)
{
	if (!check_map_shape(game))
	{
		ft_free_struct(game);
		ft_error_exit("Map must be rectangular.\n");
	}
	if (!check_map_elements(game))
	{
		ft_free_struct(game);
		ft_error_exit("Incorrect count of 'P', 'E' '1', or 'C' and '0'.\n");
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
}

void	ft_error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
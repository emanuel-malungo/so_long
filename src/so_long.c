/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:02:48 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/23 12:29:39 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	
	game = NULL;
	input_valid(argc, argv);
	game = init_strut();
	if (!game)
		ft_error_exit("Error");
	init_game(game, argv[1]);
	return (0);
}

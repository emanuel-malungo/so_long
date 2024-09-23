/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:20:13 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/23 12:31:12 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->m.map[i])
	{
		j = 0;
		while (game->m.map[i][j])
		{
			printf("%c", game->m.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
void	init_game(t_game *game, char *path_name)
{
	game->m.fd = open(path_name, O_RDONLY);
	if (game->m.fd == -1)
	{
		free(game->m.buffer);
		ft_free_struct(game);
		ft_putstr_fd("Error: Cannot open file.\n", 2);
		exit (EXIT_FAILURE);
	}
	get_parse_map(game);
	validate_map(game);
	print_map(game);
	close(game->m.fd);
	ft_free_struct(game);
}

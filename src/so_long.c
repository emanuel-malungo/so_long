/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:00:13 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 15:08:57 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			printf("%c", game->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_open_file(t_game **game, char *path_name)
{
	if (!check_extension(path_name))
		ft_error_exit("Invalid file extension\n");
	(*game)->fd = open(path_name, O_RDONLY);
	if ((*game)->fd <= 0)
		ft_error_exit("Failed to open file\n");
	get_parse_map(game);
	if (!(*game)->map)
		ft_error_exit("Error loading the map\n");
	close((*game)->fd);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		ft_error_exit("Usage: ./so_long <map_file>\n");
	game = init_game();
	if (!game)
		ft_error_exit("Failed to initialize game");
	ft_open_file(&game, argv[1]);
	print_map(game);
	free_game(game);
	return (0);
}

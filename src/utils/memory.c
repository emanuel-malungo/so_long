/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:00:47 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 14:56:35 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i]);
	free(split);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->buffer = NULL;
	game->fd = 0;
	return (game);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (!game)
		return ;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free(game);
}

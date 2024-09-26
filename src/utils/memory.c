/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:51:51 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:54:37 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_game	*init_strut(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->m.fd = 0;
	game->m.rows = 0;
	game->m.cols = 0;
	game->m.map = NULL;
	game->m.count_p = 0;
	game->m.count_e = 0;
	game->m.count_c = 0;
	game->m.count_move = 0;
	game->m.buffer = NULL;
	game->mlx_ptr = NULL;
	game->mlx_ptr = NULL;
	return (game);
}

void	ft_free_struct(t_game *game)
{
	int	i;

	if (!game)
		return ;
	i = 0;
	if (game->m.map != NULL)
	{
		while (game->m.map[i])
		{
			free(game->m.map[i]);
			i++;
		}
		free(game->m.map);
	}
	free(game);
}

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	new_ptr = NULL;
	if (!ptr)
	{
		new_ptr = malloc(new_size);
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

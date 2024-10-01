/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:28:07 by emalungo          #+#    #+#             */
/*   Updated: 2024/10/01 13:52:45 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	calculate_map_dimensions(t_game *game)
{
	game->m.cols = 0;
	game->m.rows = 0;
	while (game->m.map[0][game->m.cols])
		game->m.cols++;
	while (game->m.map[game->m.rows])
		game->m.rows++;
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

void	*read_and_resize_buffer(t_game *game, size_t *t_read, size_t *buffer_s)
{
	ssize_t	bytes_r;
	char	*temp;

	bytes_r = read(game->m.fd, game->m.buffer + *t_read, *buffer_s - *t_read);
	if (bytes_r < 0)
	{
		free(game->m.buffer);
		return (NULL);
	}
	if (bytes_r == 0)
		return (NULL);
	*t_read += bytes_r;
	if (*t_read >= *buffer_s)
	{
		*buffer_s *= 2;
		temp = ft_realloc(game->m.buffer, *buffer_s, *t_read);
		if (!temp)
		{
			free(game->m.buffer);
			return (NULL);
		}
		game->m.buffer = temp;
	}
	return (game->m.buffer);
}

void	*read_map(t_game *game)
{
	char	*buffer;
	size_t	t_read;
	size_t	buffer_s;

	t_read = 0;
	buffer_s = 8024;
	buffer = (char *)malloc(sizeof(char) * buffer_s);
	if (!buffer)
		return (NULL);
	game->m.buffer = buffer;
	while (1)
	{
		if (!read_and_resize_buffer(game, &t_read, &buffer_s))
			break ;
	}
	game->m.buffer[t_read] = '\0';
	return (game->m.buffer);
}

void	get_parse_map(t_game *game)
{
	if (!read_map(game) || !game->m.buffer)
		ft_error_exit("Error: reading map");
	check_buffer(game);
	game->m.map = ft_split(game->m.buffer, '\n');
	free(game->m.buffer);
	if (!game->m.map)
	{
		ft_free_struct(game);
		ft_error_exit("Error splitting map\n");
	}
}

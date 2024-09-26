/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:28:07 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/26 11:53:36 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	int	i;

	i = 0;
	if (!read_map(game) || !game->m.buffer)
		ft_error_exit("Error: reading map");
	if (game->m.buffer[0] == '\n')
	{
		free(game->m.buffer);
		ft_error_exit("Error: map cannot start with a newline\n");
	}
	while (game->m.buffer[i])
		i++;
	if (game->m.buffer[i - 1] == '\n')
	{
		free(game->m.buffer);
		ft_error_exit("Error: map cannot start with a newline\n");
	}
	game->m.map = ft_split(game->m.buffer, '\n');
	free(game->m.buffer);
	if (!game->m.map)
	{
		ft_free_struct(game);
		ft_error_exit("Error splitting map\n");
	}
}

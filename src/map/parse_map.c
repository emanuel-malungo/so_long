/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:00:24 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 14:57:51 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	get_parse_map(t_game **game)
{
	ssize_t	byts;

	(*game)->buffer = (char *)malloc(sizeof(char) * 1024);
	if (!(*game)->buffer)
		return ;
	byts = read((*game)->fd, (*game)->buffer, 1024);
	if (byts == -1)
		return ;
	(*game)->buffer[byts] = '\0';
	(*game)->map = ft_split((*game)->buffer, '\n');
	if (!(*game)->map)
		return ;
	free((*game)->buffer);
}

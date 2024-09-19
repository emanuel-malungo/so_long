/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:00:40 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 14:26:42 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_error_exit(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

int	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i)
	{
		if (str[i] == 'r' && str[i - 1] == 'e')
		{
			if (str[i - 2] == 'b' && str[i - 3] == '.')
				if (str[i - 4] != '\0')
					return (1);
		}
		i--;
	}
	return (0);
}

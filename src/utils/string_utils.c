/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emalungo <emalungo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:00:56 by emalungo          #+#    #+#             */
/*   Updated: 2024/09/19 14:48:18 by emalungo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_printf(char	*format, ...)
{
	char	*next;
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			next = va_arg(args, char *);
			while (*next)
			{
				write(1, next, 1);
				next++;
			}
			format += 2;
		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(args);
}

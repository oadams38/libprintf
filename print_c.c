/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:54:59 by oadams            #+#    #+#             */
/*   Updated: 2020/11/26 13:04:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	print_c(int *params, va_list arg, int *printed)
{
	char	*field;
	int		field_size;
	char	c;

	c = va_arg(arg, int);
	field_size = params[8];
	if (field_size > 1)
	{
		field = ft_newfield(field_size, ' ');
		if (params[3])
			field[0] = c;
		else
			field[field_size - 1] = c;
		*printed += ft_putstr(field);
		free((void*)field);
	}
	else
		*printed += ft_putchar(c);
}

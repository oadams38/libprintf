/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:41 by oadams            #+#    #+#             */
/*   Updated: 2020/12/14 17:15:16 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		*printed += print_field(field, field_size);
		free((void*)field);
	}
	else
		*printed += ft_putchar(c);
}

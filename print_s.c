/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:57 by oadams            #+#    #+#             */
/*   Updated: 2020/12/18 12:37:21 by oadams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(int *params, va_list arg, int *printed)
{
	char	*field;
	int		field_size;
	char	*s;
	int		s_size;
	int		precision;

	s = va_arg(arg, char *);
	field_size = params[8];
	precision = params[9];
	s_size = ft_strlen(s);
	if (precision != -1)
		s_size = precision < s_size ? precision : s_size;
	if (field_size > s_size)
	{
		field = ft_newfield(field_size, ' ');
		if (params[3])
			ft_strncpy(field, s, s_size);
		else
			ft_strncpy(&field[field_size - s_size], s, s_size);
		*printed += ft_putstr(field);
		free((void*)field);
	}
	else
	{
		while (s_size--)
			*printed += ft_putchar(*s++);
	}
}

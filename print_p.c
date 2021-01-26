/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:53 by oadams            #+#    #+#             */
/*   Updated: 2021/01/26 10:06:10 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(int *params, va_list arg, int *printed)
{
	char	*field;
	int		field_size;
	void	*p;
	char	*s;
	int		s_size;

	p = va_arg(arg, void *);
	s = voidp_to_hex(p, 'x');
	field_size = params[8];
	s_size = ft_strlen(s);
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
		*printed += ft_putstr(s);
	free((void*)s);
}

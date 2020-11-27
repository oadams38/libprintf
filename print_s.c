/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:57 by oadams            #+#    #+#             */
/*   Updated: 2020/11/27 10:49:58 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

void	print_s(int *params, va_list arg, int *printed)
{
	char	*field;
	int		field_size;
	char	*s;
	int		s_size;

	s = va_arg(arg, char *);
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
}

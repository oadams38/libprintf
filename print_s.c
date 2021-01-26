/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:57 by oadams            #+#    #+#             */
/*   Updated: 2021/01/26 14:15:21 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_null(int *params, int *printed)
{	
	int		field_size;
	int		precision;
	char	*nullissime;

	nullissime = ft_strnew(6);
	ft_strcpy(nullissime, "(null)");
	field_size = params[8];
	precision = params[9];
	if (precision == -1 || precision >= 6 || (precision != 0 && params[3] == 2))
		precision = 6;
	if (precision >= 1)
	{
		*printed += ft_printf("%.*s", precision, nullissime);
		field_size -= precision;
	}
	while (field_size-- > 0)
		*printed += ft_putchar(' ');
	free((void*)nullissime);
	return ;

}

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
	if (s == NULL)
	{
		deal_with_null(params, printed);
		return ;
	}
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

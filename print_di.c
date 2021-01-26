/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:44 by oadams            #+#    #+#             */
/*   Updated: 2021/01/26 15:03:50 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_int_arg(va_list arg, int *params)
{
	if (params[6] == 1)
		return ((int)va_arg(arg, long int));
	if (params[6] == 2)
		return ((int)va_arg(arg, long long int));
	return (va_arg(arg, int));
}

static char	get_pref(int *params, int n)
{
	if (n < 0)
		return ('-');
	if (params[2])
		return ('+');
	if (params[0])
		return (' ');
	return ('\0');
}

char		*get_s(int n, int *params)
{
	char	*s;

	if (n == -2147483648)
	{
		s = ft_strnew(10);
		ft_strcpy(s, "2147483648");
	}
	else
	{
		n *= n < 0 ? -1 : 1;
		if ((s = ft_ltoa_base((long)n, params, get_padding(params), 10))
				== NULL)
			return ;
	}
}

void		print_di(int *params, va_list arg, int *printed)
{
	char	*field;
	int		n;
	char	*s;
	int		s_size;
	char	pref;

	n = get_int_arg(arg, params);
	pref = get_pref(params, n);
	params[2] = pref == '-' ? 1 : params[2];
	s = get_s(n, params);
	if (params[8] > (s_size = ft_strlen(s)))
	{
		if ((field = ft_newfield(params[8], get_padding(params))) == NULL)
			return ;
		field = fill_field(params, field, s, pref);
		*printed += print_field(field, params[8]);
		free((void*)field);
	}
	else
		*printed += (pref > 0) ? ft_putchar(pref) + print_field(s, s_size)
			: print_field(s, s_size);
	free((void*)s);
}

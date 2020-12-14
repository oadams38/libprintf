/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:44 by oadams            #+#    #+#             */
/*   Updated: 2020/12/14 17:19:40 by oadams           ###   ########lyon.fr   */
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

void		print_di(int *params, va_list arg, int *printed)
{
	char	*field;
	int		n;
	char	*s;
	int		s_size;
	char	pref;

	n = get_int_arg(arg, params);
	pref = get_pref(params, n);
	n *= n < 0 ? -1 : 1;
	params[9] = (params[4] == 1 && params[3] == 0 && params[9] < params[8] -
			(pref != '\0')) ? params[8] - (pref != '\0') : params[9];
	if ((s = ft_ltoa_base((long)n, params, get_padding(params), 10)) == NULL)
		return ;
	fill_zeros(s, params[4]);
	if (params[8] > (s_size = ft_strlen(s)))
	{
		if ((field = ft_newfield(params[8], get_padding(params))) == NULL)
			return ;
		field = fill_field(params, field, s, pref);
		*printed += print_field(field, params[8]);
		free((void*)field);
	}
	else
		*printed += (pref > 0) ? ft_putchar(pref) + print_field(s, s_size) : print_field(s, s_size);
	free((void*)s);
}

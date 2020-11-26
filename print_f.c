/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:54:56 by oadams            #+#    #+#             */
/*   Updated: 2020/11/26 17:27:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

double		get_double_arg(va_list arg, int *params)
{
	double	n;

	if (params[7])
		return ((int)va_arg(arg, long double));
	n = va_arg(arg, double);
	return (n);
}

static char	get_pref(int *params, double n)
{
	if (n < 0)
		return ('-');
	if (params[2])
		return ('+');
	if (params[0])
		return (' ');
	return ('\0');
}

void		print_f(int *params, va_list arg, int *printed)
{
	char	*field;
	double	n;
	char	*s;
	int		s_size;
	char	pref;

	n = get_double_arg(arg, params);
	pref = get_pref(params, n);
	n *= n < 0 ? -1 : 1;
	params[9] = (params[4] == 1 && params[3] == 0 && params[9] < params[8] -
			(pref != '\0')) ? params[8] - (pref != '\0') : params[9];
	if ((s = ft_ftoa(n, params, get_padding(params))) == NULL)
		return ;
	fill_zeros(s, pref, params[4]);
	if (params[8] > (s_size = ft_strlen(s)))
	{
		if ((field = ft_newfield(params[8], get_padding(params))) == NULL)
			return ;
		field = fill_field(params, field, s, pref);
		*printed += ft_putstr(field);
		free((void*)field);
	}
	else
		*printed += (pref > 0) ? ft_putchar(pref) + ft_putstr(s) : ft_putstr(s);
	free((void*)s);
}

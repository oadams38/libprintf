/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:50 by oadams            #+#    #+#             */
/*   Updated: 2020/11/27 10:49:51 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int			get_u_arg(va_list arg, int *params)
{
	if (params[6] == 1)
		return ((unsigned int)va_arg(arg, long int));
	if (params[6] == 2)
		return ((unsigned int)va_arg(arg, long long int));
	return (va_arg(arg, int));
}

static char	get_prefix(int *params, unsigned int n)
{
	return ('\0');
}

void		print_oux(int *params, va_list arg, int *printed, int base)
{
	char			*field;
	unsigned int	n;
	char			*s;
	int				s_size;
	char			prefix;

	n = get_u_arg(arg, params);
	prefix = get_prefix(params, n);
	params[9] = (params[4] && !params[3] && params[9] < params[8] -
			(prefix != '\0')) ? params[8] - (prefix != '\0') : params[9];
	if ((s = ft_ltoa_base((long)n, params, get_padding(params), base)) == NULL)
		return ;
	fill_zeros(s, prefix, params[4]);
	if (params[8] > (s_size = ft_strlen(s)))
	{
		if ((field = ft_newfield(params[8], get_padding(params))) == NULL)
			return ;
		field = fill_field(params, field, s, prefix);
		*printed += ft_putstr(field);
		free((void*)field);
	}
	else
		*printed += ft_putstr(s);
	free((void*)s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:50 by oadams            #+#    #+#             */
/*   Updated: 2020/12/18 14:02:45 by oadams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_u_arg(va_list arg, int *params)
{
	if (params[6] == 1)
		return ((unsigned int)va_arg(arg, long int));
	if (params[6] == 2)
		return ((unsigned int)va_arg(arg, long long int));
	return (va_arg(arg, int));
}

void		print_oux(int *params, va_list arg, int *printed, int base)
{
	char			*field;
	unsigned int	n;
	char			*s;
	int				s_size;

	n = get_u_arg(arg, params);
	if ((s = ft_ltoa_base((long)n, params, get_padding(params), base)) == NULL)
		return ;
	if (params[8] > (s_size = ft_strlen(s)))
	{
		if ((field = ft_newfield(params[8], get_padding(params))) == NULL)
			return ;
		field = fill_field(params, field, s, '\0');
		*printed += ft_putstr(field);
		free((void*)field);
	}
	else
		*printed += ft_putstr(s);
	free((void*)s);
}

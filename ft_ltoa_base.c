/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:29 by oadams            #+#    #+#             */
/*   Updated: 2020/12/18 14:26:29 by oadams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_str(int *params, char *str, long n, long base)
{
	int		i;
	char	*basechars;

	i = 0;
	while (str[i])
		i++;
	basechars = params[10] == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	while (n > 0)
	{
		str[--i] = basechars[n % base];
		n /= base;
	}
	if (params[1])
	{
		if (params[10] == 'o')
			str[--i] = '0';
		if (params[10] == 'x' || params[10] == 'X')
		{
			str[--i] = params[10];
			str[--i] = '0';
		}
	}
}

static void		fill_0(char *str, long precision)
{
	int	j;

	j = -1;
	while (str[++j])
		;
	while (precision-- > 0)
		str[--j] = '0';
}

static char		*exceptions(long n, long precision)
{
	char	*str;

	if (n == 0)
	{
		if (precision == 0)
		{
			str = ft_strnew(0);
			return (str);
		}
		if ((str = ft_newfield(precision, '0')) == NULL)
			return (NULL);
		return (str);
	}
	return (NULL);
}

char			*ft_ltoa_base(long n, int *params, char padding, long base)
{
	char	*field;
	long	i;
	long	tmp;
	long	field_size;
	long	precision;

	precision = (long)params[9];
	if (n == 0)
		return (exceptions(n, precision));
	i = (params[1] && ft_strhasc("oxX", params[10]));
	i += (i == 1 && ft_strhasc("xX", params[10]));
	tmp = n;
	while (tmp > 0 && ++i)
		tmp /= base;
	field_size = i > precision ? i : precision;
	if ((field = ft_newfield(field_size, padding)) == NULL)
		return (NULL);
	fill_0(field, precision);
	fill_str(params, field, n, base);
	return (field);
}

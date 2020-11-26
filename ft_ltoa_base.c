/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:55:11 by oadams            #+#    #+#             */
/*   Updated: 2020/11/26 17:31:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

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

static void		fill_0(char *str, long i, long precision)
{
	int	j;

	j = -1;
	while (precision-- > 0)
		str[++j] = '0';
}

static char		*exceptions(long n, long precision, char padding)
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
		return (exceptions(n, precision, padding));
	i = (params[1] && ft_strhasc("oxX", params[10]));
	i += (i == 1 && ft_strhasc("xX", params[10]));
	tmp = n;
	while (tmp > 0 && ++i)
		tmp /= base;
	field_size = i > precision ? i : precision;
	if ((field = ft_newfield(field_size, padding)) == NULL)
		return (NULL);
	fill_0(field, i, precision);
	fill_str(params, field, n, base);
	return (field);
}
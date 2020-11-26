/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:54:20 by oadams            #+#    #+#             */
/*   Updated: 2020/11/26 17:36:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

long			get_precision(double n, int precision)
{
	int	dec;

	n = n - (double)((long)n);
	while (precision--)
		n *= 10;
	return (round_(n));
}

static void		fill_str(int *params, char *str, double n)
{
	int		i;
	char	*basechars;
	long	dec;
	long	integer;
	int		precision;

	i = (int)ft_strlen(str);
	basechars = params[10] == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	precision = params[9];
	if (precision > 0)
	{
		dec = get_precision(n, precision);
		while (dec >= 1)
		{
			str[--i] = basechars[dec % 10];
			dec /= 10;
		}
		i--;
	}
	integer = precision > 0 ? (long)n : round_(n);
	while (integer >= 1)
	{
		str[--i] = basechars[integer % 10];
		integer /= 10;
	}
}

static void		fill_0(char *str, int i, int precision)
{
	int	j;

	j = -1;
	while (i-- > 0)
		str[++j] = '0';
	if (precision > 0)
		str[++j] = '.';
	while (precision-- > 0)
		str[++j] = '0';
}

static char		*exceptions(double n, int precision, char padding)
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

char			*ft_ftoa(double n, int *params, char padding)
{
	char	*field;
	int		i;
	double	tmp;
	int		field_size;
	int		precision;

	precision = params[9];
	if (n == 0)
		return (exceptions(n, precision, padding));
	i = 0;
	tmp = n;
	while (tmp >= 1 && ++i)
		tmp /= 10;
	field_size = precision > 0 ? i + precision + 1 : i;
	if ((field = ft_newfield(field_size, padding)) == NULL)
		return (NULL);
	fill_0(field, i, precision);
	fill_str(params, field, n);
	return (field);
}

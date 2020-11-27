/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1_numconv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:50:04 by oadams            #+#    #+#             */
/*   Updated: 2020/11/27 10:50:05 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_atoi(const char *nptr)
{
	unsigned int	i;
	int				sign;
	unsigned int	n;

	n = 0;
	i = 0;
	sign = 1;
	while (nptr[i] && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(nptr[i]))
		n = n * 10 + nptr[i++] - '0';
	if (n > 2147483647)
	{
		if (n == 2147483648 && sign == -1)
			return (-2147483648);
		return (0);
	}
	return ((int)n * sign);
}

void	voidp_to_hex_2(char *hex, char *num, long int n)
{
	int	i;

	i = 0;
	if (n > 0)
	{
		voidp_to_hex_2(hex, num, n / 16);
		while (num[i])
			i++;
		num[i] = hex[n % 16];
	}
}

char	*voidp_to_hex(void *p, char x)
{
	long int	n;
	char		*hex;
	char		*num;

	n = (long int)p;
	hex = x == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	num = ft_strnew(30);
	num[0] = '0';
	num[1] = x;
	voidp_to_hex_2(hex, num, n);
	return (num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:50:07 by oadams            #+#    #+#             */
/*   Updated: 2020/12/14 17:14:40 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_n(int n)
{
	char	c;

	if (n > 0)
	{
		c = (unsigned char)(n % 10 + '0');
		print_n(n / 10);
		write(1, &c, 1);
	}
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	print_n(n);
}

int			ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int			ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int		print_field(char *field, int field_size)
{
	int		i;

	i = 0;
	while (i < field_size)
		write(1, &field[i++], 1);
	return (i);
}

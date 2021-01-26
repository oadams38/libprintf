/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:32 by oadams            #+#    #+#             */
/*   Updated: 2021/01/26 13:30:06 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flag(int *params, char c)
{
	if (ft_strhasc("+-#0 ", c))
		params[((int)c - 30) / 5 + (int)c / 48] += 1;
	if (c == 'h')
		params[5] += 1;
	if (c == 'l')
		params[6] += 1;
	if (c == 'L')
		params[7] += 1;
}

int		fake_call_print_normal(char c, int *printed)
{
	*printed = *printed + 1;
	ft_putchar(c);
	return (0);
}

int		get_param_element(const char *str, va_list arg, int *params, int elem)
{
	int		i;
	int		n;

	i = 0;
	if (str[i] == '*')
	{
		n = va_arg(arg, int);
		if (n < 0)
		{
			n *= -1;
			params[3] = 2;
		}
		params[elem] = n;
		return (1);
	}
	n = ft_atoi(str);
	if (n < 0)
	{
		n *= -1;
		params[3] = 2;
	}
	params[elem] = n;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

int		parse_and_print(const char *str, va_list arg, int *printed)
{
	int		i;
	int		params[11];

	i = 10;
	while ((params[i] = 0) == 0 && i > 0)
		i--;
	while (str[++i] && ft_strhasc("+-#0 ", str[i]))
		add_flag(params, str[i]);
	i += get_param_element(&str[i], arg, params, 8);
	params[9] = -1;
	if (str[i] && str[i + 1] && str[i] == '.' && (++i))
		i += get_param_element(&str[i], arg, params, 9);
	while (str[i] && ft_strhasc("lhL", str[i]))
		add_flag(params, str[i++]);
	if (ft_strhasc("cspdiuxXf", str[i]))
		params[10] = (int)str[i];
	else
		return (fake_call_print_normal(str[0], printed));
	special_print(params, arg, printed);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		*printed;
	va_list	arg;

	va_start(arg, format);
	printed = malloc(sizeof(int));
	*printed = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%' && (*printed += 1))
				ft_putchar(format[i++]);
			else
				i += parse_and_print(&format[i], arg, printed);
		}
		else if ((*printed += 1))
			ft_putchar(format[i]);
	}
	va_end(arg);
	i = *printed;
	free((void*)printed);
	return (i);
}

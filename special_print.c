/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:54:44 by oadams            #+#    #+#             */
/*   Updated: 2020/11/26 17:39:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	get_padding(int *params)
{
	if (params[4] == 1 && params[3] == 0 && params[9] == 0)
		return ('0');
	return (' ');
}

void	fill_zeros(char *s, char prefix, int zero)
{
	int	i;

	i = -1;
	if (zero == 1)
	{
		while (s[++i] && s[i] == ' ')
			s[i] = '0';
	}
	return ;
}

char	*fill_field(int *params, char *field, char *s, char prefix)
{
	int	s_size;
	int	field_size;

	s_size = ft_strlen(s);
	field_size = params[8];
	if (params[3] && ft_strncpy(&field[prefix != '\0'], s, s_size) != NULL)
		field[0] = prefix != '\0' ? prefix : field[0];
	else if (ft_strncpy(&field[field_size - s_size], s, s_size) != NULL)
		field[field_size - s_size - 1] = prefix != '\0' ?
			prefix : field[field_size - s_size - 1];
	return (field);
}

void	print_add_prefix(char *s, int precision, char prefix, int *printed)
{
	int	i;

	i = -1;
	while (s[++i] && !ft_isdigit(s[i]))
		ft_putchar(s[i]);
	if (prefix != '\0')
		ft_putchar(prefix);
	while (s[i])
		ft_putchar(s[i++]);
}

void	special_print(int *params, va_list arg, int *printed)
{
	if (params[10] == 'c')
		print_c(params, arg, printed);
	if (params[10] == 's')
		print_s(params, arg, printed);
	if (params[10] == 'p')
		print_p(params, arg, printed);
	if (params[10] == 'd' || params[10] == 'i')
		print_di(params, arg, printed);
	if (params[10] == 'o')
		print_oux(params, arg, printed, 8);
	if (params[10] == 'u')
		print_oux(params, arg, printed, 10);
	if (params[10] == 'x' || params[10] == 'X')
		print_oux(params, arg, printed, 16);
	if (params[10] == 'f')
		print_f(params, arg, printed);
}

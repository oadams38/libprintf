/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:36 by oadams            #+#    #+#             */
/*   Updated: 2020/12/18 13:40:35 by oadams           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_strhasc(char *str, char c);
int		ft_atoi(const char *nptr);
char	*ft_ltoa_base(long n, int *params, char padding, long base);
char	*ft_ftoa(double n, int *params, char padding);
char	*voidp_to_hex(void *p, char x);
int		ft_isdigit(char c);
int		ft_isspace(int c);
char	*ft_newfield(size_t size, char c);
char	*ft_strnew(size_t size);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_strlen(char *str);
void	ft_putnbr(int n);
int		ft_strlen(char *s);
int		print_field(char *field, int field_size);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcpy(char *dest, const char *src);
void	special_print(int *params, va_list arg, int *printed);
char	get_padding(int *params);
void	fill_zeros(char *s, int zero);
char	*fill_field(int *params, char *field, char *s, char prefix);
long	round_(double n);
void	print_c(int *params, va_list arg, int *printed);
void	print_s(int *params, va_list arg, int *printed);
void	print_p(int *params, va_list arg, int *printed);
void	print_di(int *params, va_list arg, int *printed);
void	print_oux(int *params, va_list arg, int *printed, int base);
void	print_f(int *params, va_list arg, int *printed);

#endif

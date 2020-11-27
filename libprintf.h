/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:49:36 by oadams            #+#    #+#             */
/*   Updated: 2020/11/27 10:49:39 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char *format, ...);
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
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcpy(char *dest, const char *src);
void	special_print(int *params, va_list arg, int *printed);
char	get_padding(int *params);
void	fill_zeros(char *s, char prefix, int zero);
char	*fill_field(int *params, char *field, char *s, char prefix);
void	print_add_prefix(char *s, int precision, char prefix, int *printed);
long	round_(double n);
void	print_c(int *params, va_list arg, int *printed);
void	print_s(int *params, va_list arg, int *printed);
void	print_p(int *params, va_list arg, int *printed);
void	print_di(int *params, va_list arg, int *printed);
void	print_oux(int *params, va_list arg, int *printed, int base);
void	print_f(int *params, va_list arg, int *printed);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:56:25 by oadams            #+#    #+#             */
/*   Updated: 2021/01/26 14:16:56 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		main(int argc, char **argv)
{
	int		ret_me;
	int		ret_pc;

	ret_me = ft_printf(" %.*s \n", -2, NULL);
	ret_pc = printf(" %.*s \n", -2, NULL);

	printf("me: %d\npc: %d\n", ret_me, ret_pc);
	return (0);
}

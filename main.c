/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadams <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:56:25 by oadams            #+#    #+#             */
/*   Updated: 2020/12/14 17:08:24 by oadams           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int		ret_me;
	int		ret_pc;

	ret_me = ft_printf(" -%*c* -%-*c* \n", -3, 0, 3, 0);
	ret_pc = printf(" -%*c* -%-*c* \n", -3, 0, 3, 0);

	printf("me: %d\npc: %d\n", ret_me, ret_pc);
	return (0);
}

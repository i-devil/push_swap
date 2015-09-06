/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 11:28:22 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/06 11:28:24 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		total_operations(int t)
{
	ft_putstr("\033[31mTotal: ");
	ft_putnbr(t);
	ft_putstr(" actions\033[37m\n");
}

void		print_stack(int *stack, char c, int len)
{
	int		i;

	ft_putchar(c);
	ft_putstr(": ");
	i = 0;
	while (i < len)
	{
		ft_putnbr(stack[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void		stack_status(t_env *env)
{
	ft_putchar('\n');
	print_stack(env->stack_a, 'a', env->len_a);
	print_stack(env->stack_b, 'b', env->len_b);
	ft_putchar('\n');
}

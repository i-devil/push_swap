/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 11:28:29 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/06 11:28:31 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_ascending(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1] && len > 1)
			return (0);
		i++;
	}
	return (1);
}

int		is_descending(int *stack, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1] && len > 1)
			return (0);
		i++;
	}
	return (1);
}

int		min_pos(int *stack, int len)
{
	int i;
	int min;
	int index;

	i = 1;
	min = stack[0];
	index = 0;
	while (i < len)
	{
		if (stack[i] < min)
		{
			min = stack[i];
			index = i;
		}
		i++;
	}
	return (index + 1);
}

void	sort_stack(t_env *env, t_flags *flag)
{
	check_swaps(env, flag);
	while (env->len_a > 0)
	{
		if (is_ascending(env->stack_a, env->len_a) &&
			is_descending(env->stack_b, env->len_b))
			break ;
		if (min_pos(env->stack_a, env->len_a) == 1)
			push_b(env, flag);
		else if (min_pos(env->stack_a, env->len_a) <= env->len_a / 2)
			rotate_a(env, flag);
		else if (min_pos(env->stack_a, env->len_a) > env->len_a / 2)
			reverse_rotate_a(env, flag);
	}
	while (env->len_b > 0)
		push_a(env, flag);
}

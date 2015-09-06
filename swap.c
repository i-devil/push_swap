/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 11:26:26 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/06 11:26:43 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_env *env, t_flags *flag)
{
	int	tmp;

	if (env->len_a < 2)
		return ;
	tmp = env->stack_a[0];
	env->stack_a[0] = env->stack_a[1];
	env->stack_a[1] = tmp;
	env->count += 1;
	ft_putstr("sa ");
	if (flag->v == 1)
		stack_status(env);
}

void	swap_b(t_env *env, t_flags *flag)
{
	int	tmp;

	if (env->len_b < 2)
		return ;
	tmp = env->stack_b[0];
	env->stack_b[0] = env->stack_b[1];
	env->stack_b[1] = tmp;
	env->count += 1;
	ft_putstr("sb ");
	if (flag->v == 1)
		stack_status(env);
}

void	swap_s(t_env *env, t_flags *flag)
{
	swap_a(env, flag);
	swap_b(env, flag);
	ft_putstr("ss ");
	if (flag->v == 1)
		stack_status(env);
	env->count -= 1;
}

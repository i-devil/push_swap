/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:51:13 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:51:21 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_env *env, t_flags *flag)
{
	int	tmp;
	int	i;

	if (env->len_a < 2)
		return ;
	tmp = env->stack_a[0];
	i = 0;
	while (i < env->len_a)
	{
		env->stack_a[i] = env->stack_a[i + 1];
		i++;
	}
	env->stack_a[env->len_a - 1] = tmp;
	env->count += 1;
	ft_putstr("\033[36mra \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

void	rotate_b(t_env *env, t_flags *flag)
{
	int	tmp;
	int	i;

	if (env->len_b < 2)
		return ;
	tmp = env->stack_b[0];
	i = 0;
	while (i < env->len_b)
	{
		env->stack_b[i] = env->stack_b[i + 1];
		i++;
	}
	env->stack_b[env->len_b - 1] = tmp;
	env->count += 1;
	ft_putstr("\033[36mrb \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

void	rotate_r(t_env *env, t_flags *flag)
{
	rotate_a(env, flag);
	rotate_b(env, flag);
	env->count -= 1;
	ft_putstr("\033[36mrr \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

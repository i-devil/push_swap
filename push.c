/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:49:34 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:49:37 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_env *env, t_flags *flag)
{
	int	i;

	if (env->len_b == 0)
		return ;
	i = env->len_a;
	while (i > 0)
	{
		env->stack_a[i] = env->stack_a[i - 1];
		i--;
	}
	env->stack_a[0] = env->stack_b[0];
	env->len_a += 1;
	env->len_b -= 1;
	i = 0;
	while (i < env->len_b)
	{
		env->stack_b[i] = env->stack_b[i + 1];
		i++;
	}
	env->count += 1;
	ft_putstr("\033[32mpa \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

void	push_b(t_env *env, t_flags *flag)
{
	int	i;

	if (env->len_a == 0)
		return ;
	i = env->len_b;
	while (i > 0)
	{
		env->stack_b[i] = env->stack_b[i - 1];
		i--;
	}
	env->stack_b[0] = env->stack_a[0];
	env->len_b += 1;
	env->len_a -= 1;
	i = 0;
	while (i < env->len_a)
	{
		env->stack_a[i] = env->stack_a[i + 1];
		i++;
	}
	env->count += 1;
	ft_putstr("\033[32mpb \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

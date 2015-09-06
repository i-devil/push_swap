/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:49:43 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:49:45 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_env *env, t_flags *flag)
{
	int	tmp;
	int	i;

	if (env->len_a < 2)
		return ;
	i = env->len_a - 1;
	tmp = env->stack_a[i];
	while (i >= 0)
	{
		env->stack_a[i] = env->stack_a[i - 1];
		i--;
	}
	env->stack_a[0] = tmp;
	env->count += 1;
	ft_putstr("\033[35mrra \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

void	reverse_rotate_b(t_env *env, t_flags *flag)
{
	int	tmp;
	int	i;

	if (env->len_b < 2)
		return ;
	i = env->len_b - 1;
	tmp = env->stack_b[i];
	while (i >= 0)
	{
		env->stack_b[i] = env->stack_b[i - 1];
		i--;
	}
	env->stack_b[0] = tmp;
	env->count += 1;
	ft_putstr("\033[35mrrb \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

void	reverse_rotate_r(t_env *env, t_flags *flag)
{
	reverse_rotate_a(env, flag);
	reverse_rotate_b(env, flag);
	env->count -= 1;
	ft_putstr("\033[35mrrr \033[37m");
	if (flag->v == 1)
		stack_status(env);
}

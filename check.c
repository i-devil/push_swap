/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 11:27:19 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/06 11:27:21 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_params(t_flags *flag, char **argv)
{
	int		i;

	i = 0;
	if (argv[1][0] == '-')
	{
		i = 1;
		while (argv[1][i])
		{
			if (argv[1][i] == 'v')
			{
				flag->v = 1;
				flag->d = 1;
			}
			else if (argv[1][i] == 't')
			{
				flag->t = 5;
				flag->d = 1;
			}
			else if (argv[1][i] >= '0' && argv[1][i] <= '9')
				;
			else
				ft_puterror("Error\n");
			i++;
		}
	}
}

void		check_errors(t_env *env, char **argv)
{
	int		i;
	int		j;

	i = env->i;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') &&
				(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
			{
				if (argv[i][j - 1] >= '0' && argv[i][j - 1] <= '9')
					ft_puterror("Error\n");
			}
			else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				;
			else
				ft_puterror("Error\n");
			j++;
		}
		i++;
	}
}

void		check_double(t_env *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->len_a)
	{
		j = i + 1;
		while (j < env->len_a)
		{
			if (env->stack_a[i] == env->stack_a[j])
				ft_puterror("Error : Twice the same number\n");
			j++;
		}
		i++;
	}
}

void		check_swaps(t_env *env, t_flags *flag)
{
	int		len;

	len = env->len_a;
	if (env->stack_a[0] > env->stack_a[1])
		swap_a(env, flag);
	while (env->stack_a[0] > env->stack_a[len - 1])
		reverse_rotate_a(env, flag);
	if (env->stack_a[len - 2] > env->stack_a[len - 1])
	{
		while (env->stack_a[len - 2] > env->stack_a[len - 1])
		{
			reverse_rotate_a(env, flag);
			reverse_rotate_a(env, flag);
			swap_a(env, flag);
			rotate_a(env, flag);
			rotate_a(env, flag);
		}
	}
}

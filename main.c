/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:50:56 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:50:57 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(0);
}

void	fill_env(t_env *env, t_flags *flag, int argc)
{
	if (flag->d == 1)
	{
		env->len_a = argc - 2;
		env->len_b = 0;
		env->len_max = env->len_a;
		env->count = 0;
		env->i = 2;
		env->j = 0;
	}
	else
	{
		env->len_a = argc - 1;
		env->len_b = 0;
		env->len_max = env->len_a;
		env->count = 0;
		env->i = 1;
		env->j = 0;
	}
}

void	init(t_env *env, t_flags *flag, char **argv, int argc)
{
	flag->v = 0;
	flag->t = 0;
	flag->d = 0;
	check_params(flag, argv);
	fill_env(env, flag, argc);
	check_errors(env, argv);
}

void	algo_and_options(t_flags *flag, t_env *env)
{
	check_double(env);
	sort_stack(env, flag);
	if (flag->v != 1)
		ft_putstr("\033[1D\n");
	if (flag->t == 5)
		total_operations(env->count);
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	env;
	t_flags	flag;

	if (argc == 1 | argc == 2)
		return (0);
	else
		init(&env, &flag, argv, argc);
	if (argc == 3 && env.len_a == env.i - 1)
		return (0);
	if ((env.stack_a = (int*)malloc(sizeof(env.stack_a) * env.len_a)) == NULL)
		return (1);
	if ((env.stack_b = (int*)malloc(sizeof(env.stack_b) * env.len_a)) == NULL)
		return (1);
	i = env.i;
	while (env.i < env.len_a + i)
	{
		env.stack_a[env.j] = ft_atoi(argv[env.i]);
		if (!ft_strequ(argv[env.i], ft_itoa(ft_atoi(argv[env.i]))))
			ft_puterror("Error\n");
		env.i++;
		env.j++;
	}
	algo_and_options(&flag, &env);
	return (0);
}

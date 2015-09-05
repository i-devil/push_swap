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

void	total_operations(int t)
{
	ft_putstr("Total: ");
	ft_putnbr(t);
	ft_putstr(" actions\n");
}

void	print_stack(int *stack, char c, int len)
{
	int	i;

	ft_putchar(c);
	ft_putstr(": ");
	// i = len - 1;
	// while (i >= 0)
	i = 0;
	while (i < len)
	{
		ft_putnbr(stack[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	stack_status(t_env *env)
{
	ft_putchar('\n');
	print_stack(env->stack_a, 'a', env->len_a);
	print_stack(env->stack_b, 'b', env->len_b);
	ft_putchar('\n');
}

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

void	check_params(t_flags *flag, char **argv)
{
	int		i;

	i = 0;
	flag->v = 0;
	flag->t = 0;
	flag->d = 0;
	if(argv[1][0] == '-')
	{
		i = 1;
		while(argv[1][i])
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
			else
				ft_puterror("Error\n");
			i++;
		}
	}
}


void	check_errors(t_env *env, char **argv)
{
	int	i;
	int j;

	i = env->i;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
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


void	check_double(t_env *env)
{
	int	i;
	int	j;

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







int		is_ascending(int *stack, int len)
{
	int i = 0;

	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1] && len > 1)
			return(0);
		i++;
	}
	return (1);
}


int		is_descending(int *stack, int len)
{
	int i = 0;

	while (i < len - 1)
	{
		if (stack[i] < stack[i + 1] && len > 1)
			return(0);
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

void	check_swaps(t_env *env, t_flags *flag)
{
	int		len;

	len = env->len_a;
	if (len == 3)
	{
		if (env->stack_a[0] > env->stack_a[1])
			swap_a(env, flag);
		while(env->stack_a[0] > env->stack_a[len - 1])
			reverse_rotate_a(env, flag);
	}
	if (env->stack_a[len - 2] > env->stack_a[len - 1])
	{
		while (env->stack_a[len - 2] > env->stack_a[len - 1])
		{
			reverse_rotate_a(env, flag);
		}
			// reverse_rotate_a(env, flag);
			// reverse_rotate_a(env, flag);
			// swap_a(env, flag);
			// rotate_a(env, flag);
			// rotate_a(env, flag);
	}
}





void	sort_stack(t_env *env, t_flags *flag)
{
	check_swaps(env, flag);
	while (env->len_a > 0)
	{
		if (is_ascending(env->stack_a, env->len_a) && is_descending(env->stack_b, env->len_b))
			break;
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



int		main(int argc, char **argv)
{
	int		i;
	t_env	env;
	t_flags	flag;

	if (argc == 1 | argc == 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		check_params(&flag, argv);
		fill_env(&env, &flag, argc);
		check_errors(&env, argv);
	}
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
	check_double(&env);
	sort_stack(&env, &flag);
	if (flag.v != 1)
		ft_putstr("\033[1D\n");
	if (flag.t == 5)
		total_operations(env.count);
	return (0);
}
















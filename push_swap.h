/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:51:05 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/06 11:38:04 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct		s_list
{
	char			*mv;
	struct s_list	*next;
}					t_list;

typedef struct		s_flags
{
	int				d;
	int				v;
	int				t;
}					t_flags;

typedef struct		s_env
{
	int				*stack_a;
	int				*stack_b;
	int				len_a;
	int				len_b;
	int				len_max;
	int				count;
	int				i;
	int				j;
	char			*str;
}					t_env;

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
int					ft_strequ(char const *s1, char const *s2);
void				push_a(t_env *env, t_flags *flag);
void				push_b(t_env *env, t_flags *flag);
void				reverse_rotate_a(t_env *env, t_flags *flag);
void				reverse_rotate_b(t_env *env, t_flags *flag);
void				reverse_rotate_r(t_env *env, t_flags *flag);
void				rotate_a(t_env *env, t_flags *flag);
void				rotate_b(t_env *env, t_flags *flag);
void				rotate_r(t_env *env, t_flags *flag);
void				swap_a(t_env *env, t_flags *flag);
void				swap_b(t_env *env, t_flags *flag);
void				swap_s(t_env *env, t_flags *flag);
void				ft_puterror(char *str);
void				fill_env(t_env *env, t_flags *flag, int argc);
void				total_operations(int t);
void				print_stack(int *stack, char c, int len);
void				stack_status(t_env *env);
int					is_ascending(int *stack, int len);
int					is_descending(int *stack, int len);
int					min_pos(int *stack, int len);
void				sort_stack(t_env *env, t_flags *flag);
void				check_params(t_flags *flag, char **argv);
void				check_errors(t_env *env, char **argv);
void				check_double(t_env *env);
void				check_swaps(t_env *env, t_flags *flag);
void				init(t_env *env, t_flags *flag, char **argv, int argc);
void				algo_and_options(t_flags *flag, t_env *env);

#endif

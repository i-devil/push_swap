/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-vill <ide-vill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 19:51:05 by ide-vill          #+#    #+#             */
/*   Updated: 2015/09/05 19:51:06 by ide-vill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

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
	int				v;
	int				t;
	int				d;
}					t_flags;

typedef struct		s_env
{
	int			*stack_a;
	int			*stack_b;
	int			len_a;
	int			len_b;
	int			len_max;
	int			count;
	int			i;
	int			j;
	char		*str;
}					t_env;


int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		*ft_memalloc(size_t size);
void		ft_putchar(char c);
void		ft_putnbr(int n);
void		ft_putstr(char const *s);
int			ft_strequ(char const *s1, char const *s2);


void				push_a(t_env *e, t_flags *f);
void				push_b(t_env *e, t_flags *f);
void				reverse_rotate_a(t_env *e, t_flags *f);
void				reverse_rotate_b(t_env *e, t_flags *f);
void				reverse_rotate_r(t_env *e, t_flags *f);
void				rotate_a(t_env *e, t_flags *f);
void				rotate_b(t_env *e, t_flags *f);
void				rotate_r(t_env *e, t_flags *f);
void				swap_a(t_env *e, t_flags *f);
void				swap_b(t_env *e, t_flags *f);
void				swap_s(t_env *e, t_flags *f);

void				check_stack(t_env *e);


void	stack_status(t_env *env);





// void				check_param(t_flags *f, char **av);
// void				settings(t_env *e, t_flags *f, int ac, char **av);
// void				ft_puterror(char *str);
// void				check_error(t_env *e, char **av);

// void				total_put(int t);
// void				print_pile(int *pile, char c, int len);
// void				stack_status(t_env *e);


// int					test_pile(int *pile, int len);
// void				sort_algo(t_env *e, t_flags *f);
// int					is_grwing(int *pile, int len);
// int					is_dscnding(int *pile, int len);
// int					lowest_pos(int *pile, int len);
// void				tricks(t_env *e, t_flags *f);





#endif

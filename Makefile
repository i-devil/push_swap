NAME	=	push_swap

SRC 	=	main.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_strequ.c \
			ft_memalloc.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c  \
			check.c \
			options.c \
			sort_stack.c

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(FLAGS) -c $(SRC)
	cc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
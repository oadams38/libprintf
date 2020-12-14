NAME = libftprintf.a

HEADER = ft_printf.h

SRCS = ft_printf.c \
		tools1_numconv.c tools2_print.c \
		tools3_simple_checks.c tools4_str.c \
		special_print.c \
		ft_ltoa_base.c \
		ft_ftoa.c \
		print_c.c \
		print_s.c \
		print_p.c \
		print_di.c \
		print_oux.c \
		print_f.c 

OBJS = ${SRCS:.c=.o}

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

FLAGS = -g -c -Wall -Werror -Wextra

$(NAME): $(OBJS) $(HEADER) 
	ar rvs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

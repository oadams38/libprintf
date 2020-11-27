NAME = libprintf.a

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

CC = gcc

FLAGS = -g -c

libft.o : 
	$(CC) $(FLAGS) $(SRCS)
	
$(NAME): libft.o 
	ar rvs $(NAME) *.o 

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: clean all

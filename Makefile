CC=gcc
AR=ar
ARFLAGS=rc
FLAGS= -Wall -Werror -Wextra
NAME=libftprintf.a
SRC= ft_printf.c \
		ft_check_format.c \
		ft_flag_dot.c \
		ft_flag_minus.c \
		ft_flag_minus2.c \
		ft_flag_star.c \
		ft_flag_star2.c \
		ft_flag_zero.c \
		ft_flag_zero2.c \
		ft_put_zero_space.c \
		ft_output.c \
		ft_width.c \
		ft_exception.c \
		ft_exception_u.c \
		ft_exception_xX.c \
		ft_exception_s.c \
		ft_extra.c \
		ft_exception_di.c \
		ft_extra_2.c \
		ft_extra_3.c \
		ft_extra_4.c \
		ft_flag_dot_2.c \
		ft_width2.c \

LIBFT=  libft/ft_strlen.c libft/ft_atoi.c  \
	libft/ft_strdup.c libft/ft_calloc.c \
	libft/ft_strjoin.c \
	libft/ft_isalpha.c libft/ft_isdigit.c \
	libft/ft_itoa.c libft/ft_itoa_base.c \
	libft/ft_len_nbr.c libft/ft_strcmp.c libft/ft_strcat.c \

OBJ = $(SRC:.c=.o)
OBJ_L = $(LIBFT:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a ./libftprintf.a
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

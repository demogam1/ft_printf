CC=gcc
AR=ar
ARFLAGS=rc
FLAGS=-Wall -Wextra -Werror
NAME=libft.a
SRC= ft_strlen.c ft_atoi.c  \
	ft_strdup.c ft_calloc.c \
	ft_strjoin.c \
	ft_isalpha.c ft_isdigit.c \
	ft_itoa.c ft_itoa_base.c \
	ft_len_nbr.c \
	ft_strcmp.c \
	ft_strcat.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

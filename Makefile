NAME = push_swap
SRC = libft/*.c printf/*.c parsing_and_main/*.c
OBJ = $(SRC:.c=.o)
CC = cc -fsanitize=address -g -Wall -Wextra -Werror


$(NAME):$(SRC)
	$(CC) $(SRC) -o $(NAME)

t:
	./push_swap 1 2 3 4 5
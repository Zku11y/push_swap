NAME = push_swap
SRC = libft/*.c printf/*.c src/*.c algorithm/*.c mods/*.c opps/*.c misc/*.c
OBJ = $(SRC:.c=.o)
CC = cc -g -Wall -Wextra -Werror


$(NAME):$(SRC)
	$(CC) $(SRC) -o $(NAME)

t:
	./push_swap 1 2 3 4 5
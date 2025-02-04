NAME = ft_push_swap.a
FILES = ft_push_swap.c
PRINTF = ./printf/ft_printf.o
OBJECT = $(FILES:.c=.o)
CC = cc -Wall -Wextra -Werror


all:
	$(CC) src/main.c libft/*.c printf/*.c -o push_swap

push:
	$(CC) $(FILES) -o push_swap $(PRINTF)
	./push_swap

$(NAME):$(OBJECT)
	ar rcs $(FILES) $(OBJECT)

%.o:%.c
	$(CC) -c $< -o $@

clean:
	rm -fr $(OBJECT)

fclean: clean
	rm -fr $(NAME)

re: fclean $(NAME)

.PHONY: clean
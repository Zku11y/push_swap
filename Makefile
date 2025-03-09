NAME = push_swap
CHECKER = checker

CC = cc
LIBFT = libft/libft.a
GNL_DIR = get_next_line
PRINTF = printf/libftprintf.a
CFLAGS = -g -Wall -Wextra -Werror

SRC = src/assign.c src/parse.c src/push_swap.c \
	  opps/push.c opps/rotate.c opps/swap.c \
	  mods/list_mods.c misc/misc1.c \
	  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	  algorithm_manager/check.c algorithm_manager/five.c algorithm_manager/four.c algorithm_manager/manager.c algorithm_manager/three.c \
	  the_algorithm/main_algorithm_manager.c the_algorithm/find_cheapest.c \
	  optimization/one_instead_of_two_ops.c

BSRC =  src/assign.c src/parse.c \
	  	opps/push.c opps/rotate.c opps/swap.c \
	  	mods/list_mods.c misc/misc1.c misc/misc2.c \
	  	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	 	algorithm_manager/check.c algorithm_manager/five.c algorithm_manager/four.c algorithm_manager/manager.c algorithm_manager/three.c \
	 	the_algorithm/main_algorithm_manager.c the_algorithm/find_cheapest.c \
	  	optimization/one_instead_of_two_ops.c \
		checker_files/checker.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

checker: $(CHECKER)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libft bonus

$(PRINTF):
	make -C printf

$(CHECKER): $(BOBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(PRINTF) -o $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)
	make -C libft clean
	make -C printf clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make -C libft fclean
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re

NAME = push_swap
BONUS = checker

CC = cc
LIBFT_DIR = includes/libft
PRINTF_DIR = includes/printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRC = 	mandatory/src/assign.c mandatory/src/parse.c mandatory/src/push_swap.c mandatory/src/misc.c \
		mandatory/opps/push.c mandatory/opps/rotate.c mandatory/opps/swap.c mandatory/mods/list_mods.c \
		mandatory/algorithm_manager/check.c mandatory/algorithm_manager/five.c \
		mandatory/algorithm_manager/four.c mandatory/algorithm_manager/manager.c \
		mandatory/algorithm_manager/three.c mandatory/algorithm_manager/main_algorithm_manager.c \

BSRC =  bonus/src/assign_bonus.c bonus/src/parse_bonus.c \
	   	bonus/src/check_bonus.c bonus/src/checker_bonus.c \
	   	bonus/src/list_mods_bonus.c bonus/opps/push_bonus.c \
	   	bonus/opps/rotate_bonus.c bonus/opps/swap_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)

	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)


$(LIBFT):
	make -C $(LIBFT_DIR) bonus


$(PRINTF):
	make -C $(PRINTF_DIR)


$(BONUS): $(BOBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(PRINTF) -o $(BONUS)


$(OBJ): %.o: %.c ./mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@


$(BOBJ): %.o: %.c ./bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ) $(BOBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean


fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean


re: fclean all

.PHONY: all clean fclean re

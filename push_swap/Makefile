NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_SRC = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRC:.c=.o)
LIBFT_HEADER = $(LIBFT_DIR)/libft.h

SRC = push_swap.c push_swap_utils.c push_swap_free.c push_swap_actions.c push_swap_rot.c push_swap_sort.c push_swap_revrot.c push_swap_index.c\
push_swap_utils_utils.c push_swap_sortbig.c
OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_SRC) $(LIBFT_HEADER)
	@make -C $(LIBFT_DIR)

%.o : %.c
	$(CC) $(FLAGS) -Iinclude -I$(LIBFT_DIR) -c $< -o $@

$(NAME) : $(OBJS) $(LIBFT)	
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	
clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all

.PHONY: re fclean clean all

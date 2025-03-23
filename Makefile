
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
SRC_FILES =push_swap.c \
			b_zero.c \
			create_link_list.c \
			free_and_write_error.c \
			ft_control_args.c \
			ft_sorting.c \
			ft_split.c \
			ft_split_utils.c \
			init_stack_a.c \
			init_stack_b.c \
			move_stack_a.c \
			move_stack_b.c \
			push_actions.c \
			rev_rotate_actions.c \
			rotate_actions.c \
			swap_actions.c \
			same_or_sort.c \
			stack_utils.c \
			two_or_many_args.c \

OBJ_FILES = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(NAME) ✅ ✅ ✅ "

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	@echo "Object files removed ✏️ ✏️ !"

fclean: clean
	rm -f $(NAME)
	@echo "Executable removed ✏️ ✏️ !"

re: fclean all

.PHONY: all clean fclean re
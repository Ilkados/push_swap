NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c Error.c free.c indexing.c Is_sorted.c op_wrappers_a.c op_wrappers_b.c op_wrappers_both.c \
   operation.c parsing.c Set_positions.c sort_stack.c  stack_init.c tiny_sort_3.c \
   turck_moves.c turck_sort.c valid_tokens.c 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

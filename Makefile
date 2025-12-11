NAME = push_swap

SRC = main.c sort_array.c list_handling.c rule_swap.c rule_push.c rule_rotate.c rule_reverse_rotate.c

CC = cc
FLAGS = -Wall -Werror -Wextra

HEAD = push_swap.h 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) -g $(OBJ) -o $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -g -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME = push_swap

SRC = main.c \
	./Dataprocessing/sort_array.c \
	./Dataprocessing/map_array.c \
	./Dataprocessing/list_handling.c \
	./Rules/rule_swap.c \
	./Rules/rule_push.c \
	./Rules/rule_rotate.c \
	./Rules/rule_reverse_rotate.c \
	./Sortalgorithm/radix_sort.c \
	./Sortalgorithm/mini_sort.c \
	./Sortalgorithm/medi_sort.c \
	./Sortalgorithm/medi_sort_help.c \

CC = cc
FLAGS = -Wall -Werror -Wextra 

HEAD = -I.
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) -g $(OBJ) -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) $(HEAD) -g -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
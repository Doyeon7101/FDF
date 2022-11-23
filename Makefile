NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC_DIR = ./srcs/
SRC2_DIR = ./srcs/

SRC_FILES = a_to_b.c b_to_a.c ft_split.c libft.c libft2.c \
			operation.c parse.c push_swap.c utils_stack.c algo_utils.c

SRC_OBJ = $(SRC_FILES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re

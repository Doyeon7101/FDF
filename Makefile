# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpark <dpark@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 17:58:14 by dpark             #+#    #+#              #
#    Updated: 2022/11/25 18:23:26 by dpark            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc
FRAEMWORKS = -framework OpenGL -framework AppKit
RM = rm -f
CFLAGS = -Werror -Wextra -Wall
INCLUDES = minilibx/libmlx.dylib

SRC = bresenham.c draw_line.c fdf.c ft_atoi_base.c  \
	ft_print_error.c ft_split.c  get_next_line.c isometric.c libft.c parse.c

all:
	make -C minilibx/ all
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	$(RM) $(SRC_OBJ)
	make -C minilibx/ clean
	$(RM) mlx.h.gch

fclean: clean
	make clean
	$(RM) $(NAME)

re: fclean all
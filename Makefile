# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 17:26:30 by gcatarin          #+#    #+#              #
#    Updated: 2023/09/26 16:59:19 by gcatarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I. #-fsanitize=address
RM				= rm -fr

NAME			= so_long
HEADER			= includes/solong.h

INCLUDE			= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SOURCES			= sources/ft_split.c sources/enemy.c sources/change_img.c sources/end.c sources/checkmap.c \
				sources/ft_utils_2.c sources/ft_utils.c sources/hooks.c sources/solong.c sources/ft_itoa.c \
				sources/get_next_line.c sources/get_next_line_utils.c sources/player.c \
					
MLX				= minilibx-linux/libmlx_Linux.a

SOURCES_O		= $(SOURCES:sources/%.c=objects/%.o)



%.o: %.c
	$(CC) $(CFLAGS) -o so_long -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:	objs minilibx $(NAME)

minilibx:
	make -C minilibx-linux/

objs:
	mkdir -p objects

$(NAME):		$(SOURCES_O)
	clear
	${CC} $(CFLAGS) $(SOURCES_O) $(MLX) $(INCLUDE) -o $(NAME)

objects/%.o: sources/%.c
	${CC} ${CFLAGS} -c $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(SOURCES_O) objs

fclean:			clean
	$(RM) $(NAME) $(SOURCES_O)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
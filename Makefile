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
SOURCES			= srcs/ft_split.c srcs/enemy.c srcs/change_img.c srcs/end.c srcs/checkmap.c \
				srcs/ft_strdup.c srcs/ft_strncmp.c srcs/ft_substr.c srcs/ft_util.c\
				srcs/hooks.c srcs/solong.c printf/functs.c printf/help.c \
				printf/prefts.c printf/tratamento.c printf/action.c printf/ft_itoa.c\
				printf/fts.c printf/ft_printf.c printf/functsbonus.c \
				srcs/get_next_line.c srcs/get_next_line_utils.c \
 					
					
MLX				= minilibx-linux/libmlx_Linux.a

SOURCES_O		= $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o so_long -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:			$(NAME)

$(NAME):		$(SOURCES_O)
	${CC} $(CFLAGS) -g $(SOURCES_O) $(MLX) $(INCLUDE) -o $(NAME)

run:
	./so_long maps/valid-map.ber

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(NAME) $(SOURCES_O)

fclean:			clean
	$(RM) $(NAME) $(SOURCES_O)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
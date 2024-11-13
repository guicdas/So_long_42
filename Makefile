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

SRCS_DIR		= srcs
OBJS_DIR		= objs
NAME			= so_long
HEADER			= includes/solong.h

MLX				= minilibx-linux/libmlx_Linux.a
INCLUDE			= -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SOURCES			= $(SRCS_DIR)/ft_split.c $(SRCS_DIR)/enemy.c $(SRCS_DIR)/change_img.c $(SRCS_DIR)/end.c $(SRCS_DIR)/checkmap.c \
				$(SRCS_DIR)/ft_utils_2.c $(SRCS_DIR)/ft_utils.c $(SRCS_DIR)/hooks.c $(SRCS_DIR)/solong.c $(SRCS_DIR)/ft_itoa.c \
				$(SRCS_DIR)/get_next_line.c $(SRCS_DIR)/get_next_line_utils.c $(SRCS_DIR)/player.c \
					
SOURCES_O		= $(SOURCES:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)



%.o: %.c
	$(CC) $(CFLAGS) -o so_long -I/usr/include -Imlx_linux -O3 -c $< -o $@

all:	minilibx $(NAME)

minilibx:
	make -C minilibx-linux/

$(OBJS_DIR):
	mkdir -p objs

$(NAME):		$(SOURCES_O)
	clear
	${CC} $(CFLAGS) $(SOURCES_O) $(MLX) $(INCLUDE) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
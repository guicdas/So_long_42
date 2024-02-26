# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcatarin <gcatarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 17:26:30 by gcatarin          #+#    #+#              #
#    Updated: 2023/04/01 15:45:25 by gcatarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I./
RM				= rm -fr

NAME			= libftprintf.a
HEADER			= ft_printf.h

SOURCES			= ft_printf.c tratamento.c help.c functs.c  \
					ft_itoa.c action.c fts.c functsbonus.c prefts.c

BONUS			=  *.c

SOURCES_O		= $(SOURCES:.c=.o)
BONUS_O		= $(BONUS:.c=.o)

all:			$(NAME)

$(NAME):		$(SOURCES_O)
	ar -rcs $(NAME) $(SOURCES_O)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(SOURCES_O) $(BONUS_O)

bonus:			$(NAME) $(BONUS_O)
	ar -rcs $(NAME) $(BONUS_O)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

rebonus:		fclean bonus

.PHONY:			all clean fclean re
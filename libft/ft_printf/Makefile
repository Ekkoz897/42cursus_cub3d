# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 13:29:27 by ratavare          #+#    #+#              #
#    Updated: 2023/04/28 11:32:32 by ratavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		libftprintf.a

CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

RM		=		rm -f

SRC 	=		srcs/ft_printf.c srcs/ft_printf_utils.c

OBJ		=		$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
		@ar rcs	$(NAME) $(OBJ)

clean:			
				$(RM) $(OBJ) $(BOBJ)

fclean: clean
				$(RM) $(NAME)

re:		fclean	$(NAME)
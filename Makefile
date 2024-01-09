NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

SRC = main.c parser.c

SRC_GNL = libft/GNL/get_next_line.c libft/GNL/get_next_line_utils.c

SRC_GNL = libft/GNL/get_next_line.c libft/GNL/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_GNL = $(SRC_GNL:.c=.o)

OBJ_GNL = $(SRC_GNL:.c=.o)

all: $(NAME)

$(NAME): $(addprefix SRC/,$(OBJ))  $(OBJ_GNL) $(OBJ_GNL)
	@make -s -C libft/ft_printf
	@make -s -C libft
	@$(CC) $(addprefix SRC/,$(OBJ)) $(OBJ_GNL) libft/ft_printf/libftprintf.a libft/libft.a -o $(NAME) -lreadline

git: fclean
	@git add .
	@git commit
	@git push
	@clear
	@echo "|                                                 |"
	@echo "|                                                 |"
	@echo "|      -------{ Commited and Pushed }-------      |"
	@echo "|                                                 |"
	@echo "|                                                 |"

commit: fclean

clean: 
	@make clean -s -C libft/ft_printf
	@make clean -s -C libft
	@$(RM) $(addprefix SRC/,$(OBJ))
	@$(RM) $(OBJ_GNL)

fclean: clean
	@make fclean -s -C libft/ft_printf
	@make fclean -s -C libft
	@$(RM) $(NAME) $(LIB)

re: fclean all
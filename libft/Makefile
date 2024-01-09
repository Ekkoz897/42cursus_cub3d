NAME	=		libft.a
FT_PRINTF=		./ft_printf/libftprintf.a

CC		=		cc

CFLAGS	=		-Wall -Wextra -Werror

RM		=		rm -f

SRC 	=		ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_strchr.c ft_strlen.c ft_strlcpy.c ft_tolower.c ft_toupper.c ft_strlcat.c\
ft_strnstr.c ft_strrchr.c ft_memset.c ft_strncmp.c ft_bzero.c ft_memcpy.c ft_memmove.c\
ft_strdup.c ft_memcmp.c ft_memchr.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c\
ft_itoa.c ft_split.c

BONUS	=		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ		=		$(SRC:.c=.o)

BOBJ	=		$(BONUS:.c=.o)

all:			$(NAME)

$(NAME):		$(BOBJ) $(OBJ) $(FT_PRINTF)
		ar rcs	$(NAME) $(OBJ) $(BOBJ)

$(FT_PRINTF):
				make -C ./ft_printf

clean:
				make clean -C ./ft_printf
				$(RM) $(OBJ) $(BOBJ)

fclean: clean
				make fclean -C ./ft_printf
				$(RM) $(NAME)

re:		fclean	$(NAME)
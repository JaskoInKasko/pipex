CC = cc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = pipex.h
SRC = Sourcecode/pipex.c Sourcecode/pipex_utils.c Sourcecode/childs.c Sourcecode/errors.c\
Sourcecode/free_all.c\

OBJ = $(SRC:.c=.o)
NAME = pipex
LIBFT = ./included_functions/libft/libft.a
FT_PRINTF = ./included_functions/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C included_functions/libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

.PHONY: all clean fclean re included_functions

clean:
	$(MAKE) -C included_functions/libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C included_functions/libft fclean
	rm -f $(NAME)

re: fclean all

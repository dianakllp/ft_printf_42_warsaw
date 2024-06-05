NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c parse_str.c print_char.c\
	put_hex.c put_nb.c put_pointer.c print_string.c put_unsigned_i.c\

OBJS = $(SRCS:.c=.o)

HEADER = ./

.c.o:
	@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

$(NAME): $(OBJS)
	@ar cr $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJS)

re: fclean all

.PHONY: clean fclean re all

NAME=	printf.a

CC=		cc
CFLAGS=	-Wall -Wextra -Werror

INCLUDE=	ft_printf.h

SRCS =

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
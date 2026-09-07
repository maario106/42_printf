NAME=	libftprintf.a

CC=		cc
CFLAGS=	-Wall -Wextra -Werror

INCLUDE=	ft_printf.h

LIBFT_DIR=	libft
LIBFT=		$(LIBFT_DIR)/libft.a

SRCS =

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
		ar rcs $(NAME) $(OBJS)
		mkdir -p .libft_objs
		cd .libft_objs && ar x ../$(LIBFT)
		ar rcs $(NAME) .libft_objs/*.o
		rm -rf .libft_objs

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
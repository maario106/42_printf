NAME=	libftprintf.a

CC=		cc
CFLAGS=	-Wall -Wextra -Werror

INCLUDE=	ft_printf.h

LIBFT_DIR=	libft
LIBFT=		$(LIBFT_DIR)/libft.a

TEST_NAME=	test

SRCS =	ft_printf.c ft_putchar_pf.c ft_puthex_pf.c ft_putnbr_pf.c \
		ft_putptr_pf.c ft_putstr_pf.c ft_putunbr_pf.c ft_putnbr_base_pf.c

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

test: $(NAME)
		$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST_NAME)

clean:
		rm -f $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME) $(TEST_NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test
NAME=	libftprintf.a

CC=		cc
CFLAGS=	-Wall -Wextra -Werror

INCLUDE=	ft_printf.h

LIBFT_DIR=	libft
LIBFT=		$(LIBFT_DIR)/libft.a

TEST_NAME=	test

SRCS =	ft_printf.c ft_putchar_pf.c ft_puthex_pf.c ft_putnbr_pf.c \
		ft_putptr_pf.c ft_putstr_pf.c ft_putunbr_pf.c ft_utils_pf.c

OBJS =	$(SRCS:.c=.o)

BONUS_SRCS =	ft_printf_bonus.c ft_parse_bonus.c ft_print_chars_bonus.c \
				ft_print_nbr_bonus.c ft_utils_bonus.c

BONUS_OBJS =	$(BONUS_SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
		rm -f $(NAME) .bonus
		ar rcs $(NAME) $(OBJS)
		mkdir -p .libft_objs
		cd .libft_objs && ar x ../$(LIBFT)
		ar rcs $(NAME) .libft_objs/*.o
		rm -rf .libft_objs

bonus: .bonus

.bonus: $(BONUS_OBJS) $(LIBFT)
		rm -f $(NAME)
		ar rcs $(NAME) $(BONUS_OBJS)
		mkdir -p .libft_objs
		cd .libft_objs && ar x ../$(LIBFT)
		ar rcs $(NAME) .libft_objs/*.o
		rm -rf .libft_objs
		touch .bonus

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

test: $(NAME)
		$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST_NAME)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME) $(TEST_NAME) .bonus
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re test
# ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_prinf(char const *chain, ...);
void	process(va_list vargs, char *chain, size_t *counter);
void	ft_putchar_pf(char c, size_t *counter);
void	ft_putstr_pf(char *s, size_t *counter);
void	ft_putnbr_pf(int n, size_t *counter);
void	ft_puthex_pf(char *hex, size_t *counter);

# endif
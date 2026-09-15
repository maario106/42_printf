# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define UPPER_HEX_BASE "0123456789ABCDEF"
# define LOWER_HEX_BASE "0123456789abcdef"

int		ft_printf(char const *chain, ...);
void	process(va_list vargs, char *chain, size_t *counter);
void	ft_putchar_pf(char c, size_t *counter);
void	ft_putstr_pf(char *s, size_t *counter);
void	ft_putnbr_pf(int n, size_t *counter);
void	ft_putunbr_pf(unsigned int n, size_t *counter);
void	ft_putptr_pf(void *, size_t *counter);
void    ft_puthex_pf(unsigned int, size_t *counter, char *base);

char	*ft_itoa_pf(int n);
int	count_digits_pf(int n);


# endif
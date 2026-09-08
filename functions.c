# include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
    (*counter)++; 
}

void	ft_putstr_pf(char *s, size_t *counter)
{
	size_t  len;

	if (!s)
		write(1, "(null)", 6);
	len = ft_strlen(s);
	write(1, s, len);
	(*counter) += len;
}

void	ft_putnbr_pf(int n, size_t *counter)
{
	char	*nbr;
	size_t  len;

	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	write(1, nbr, len);
	(*counter) += len;
	free(nbr);
}

void    ft_puthex_pf(char *hex, size_t *counter)
{

}
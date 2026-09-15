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
void	ft_putunbr_pf(unsigned int n, size_t *counter)
{
	char	*nbr;
	size_t  len;

	nbr = ft_itoa_pf(n);
	len = ft_strlen(nbr);
	write(1, nbr, len);
	(*counter) += len;
	free(nbr);
}

int	count_digits_pf(int n)
{
	int	ndigits;

	ndigits = 0;
	if (n <= 0)
		ndigits++;
	while (n != 0)
	{
		n /= 10;
		ndigits++;
	}
	return (ndigits);
}

char	*ft_itoa_pf(int n)
{
	char	*ptr;
	int		ndigits;
	int		start;
	long	nb;

	nb = n;
	ndigits = count_digits_pf(n);
	ptr = (char *)malloc(sizeof(char) * (ndigits + 1));
	if (!ptr)
		return (NULL);
	ptr[ndigits] = '\0';
	start = 0;
	while (ndigits > start)
	{
		ndigits--;
		ptr[ndigits] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ptr);
}


void	ft_putptr_pf(void *ptr, size_t *counter)
{
	ptr = NULL;
	ptr++;
	counter++;
}

void    ft_puthex_pf(unsigned int nbr, size_t *counter, char *base)
{
	counter++;
	nbr++;
	base++;
}
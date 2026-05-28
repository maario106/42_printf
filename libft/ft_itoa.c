/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:12:28 by codespace         #+#    #+#             */
/*   Updated: 2026/05/17 18:34:21 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
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

char	*ft_itoa(int n)
{
	char	*ptr;
	int		ndigits;
	int		start;
	long	nb;

	nb = n;
	ndigits = count_digits(n);
	ptr = (char *)malloc(sizeof(char) * (ndigits + 1));
	if (!ptr)
		return (NULL);
	ptr[ndigits] = '\0';
	start = 0;
	if (nb < 0)
	{
		ptr[0] = '-';
		nb = -nb;
		start = 1;
	}
	while (ndigits > start)
	{
		ndigits--;
		ptr[ndigits] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ptr);
}
// int main(void)
// {
//  int i = 2147483648;
//  printf("Tiene %d caracteres\n", count_digits(i));
//  printf("El número era: %s\n", ft_itoa(i));
//  return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:00:19 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/08 20:00:02 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process(va_list *vargs, char *chain, size_t *counter)
{
	if (*chain == 'c' || *chain == 's')
	{	
		ft_putchar_pf((char)va_arg(*vargs, int), counter);
	}
	if (*chain == 's')
	{
		ft_putstr_pf(va_arg(*vargs, char *), counter);
	}
	if (*chain == 'd' || *chain == 'i')
	{
		ft_putnbr_pf(*chain, counter);
	}
	if (*chain == 'x')
	{
		ft_puthex_pf(*chain, counter);
	}
}

int	ft_printf(char	const *chain, ...)
{
	va_list	vargs;
	size_t	counter;

	if (!chain)
		return (0);
	counter = 0;
	va_start(vargs, chain);
	while (*chain != '\0')
	{
		if (*chain == '%')
		{
			chain++;
			process(vargs, (char *)chain, &counter);
		}
		else
			write(1, chain, 1);
		chain++;
	}
	va_end(vargs);
	return (counter);
}

int	main(void)
{
	ft_printf("hola qu%e tal");
	return 0;
}
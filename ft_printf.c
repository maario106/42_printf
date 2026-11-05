/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 19:00:19 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/11/05 13:27:32 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process(va_list *vargs, char *chain, size_t *counter)
{
	if (*chain == 'c')
		ft_putchar_pf(va_arg(*vargs, int), counter);
	else if (*chain == 's')
		ft_putstr_pf(va_arg(*vargs, char *), counter);
	else if (*chain == 'i' || *chain == 'd')
		ft_putnbr_pf(va_arg(*vargs, int), counter);
	else if (*chain == 'u')
		ft_putunbr_pf(va_arg(*vargs, unsigned int), counter);
	else if (*chain == 'p')
		ft_putptr_pf(va_arg(*vargs, void *), counter);
	else if (*chain == 'x' || *chain == 'X')
	{
		if (*chain == 'x')
			ft_puthex_pf(va_arg(*vargs, unsigned int), counter, LOWER_HEX_BASE);
		else if (*chain == 'X')
			ft_puthex_pf(va_arg(*vargs, unsigned int), counter, UPPER_HEX_BASE);
	}
	else if (*chain == '%')
		ft_putchar_pf(*chain, counter);
}

int	ft_printf(char	const *chain, ...)
{
	va_list	vargs;
	size_t	counter;

	if (!chain)
		return (-1);
	counter = 0;
	va_start(vargs, chain);
	while (*chain != '\0')
	{
		if (*chain == '%')
		{
			chain++;
			if (*chain == '\0')
				return (va_end(vargs), -1);
			process(&vargs, (char *)chain, &counter);
		}
		else
		{
			write(1, chain, 1);
			counter++;
		}
		chain++;
	}
	va_end(vargs);
	return (counter);
}

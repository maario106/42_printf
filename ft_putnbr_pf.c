/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:55:45 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/11/05 13:30:55 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *counter)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_pf('-', counter);
		nbr = -nbr;
	}
	ft_putnbr_base_pf(nbr, counter, DEC_BASE);
}

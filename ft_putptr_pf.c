/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:56:54 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/16 21:47:35 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_pf(void *ptr, size_t *counter)
{
	if (ptr != NULL)
	{
		write(1, "0x", 2);
		(*counter) += 2;
		ft_putnbr_base_pf((uintptr_t) ptr, counter, LOWER_HEX_BASE);
	}
	else
	{
		write(1, "(nil)", 5);
		(*counter) += 5;
	}
}

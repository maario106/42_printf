/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:42:19 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/16 21:47:14 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_pf(uintptr_t nbr, size_t *counter, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nbr >= base_len)
		ft_putnbr_base_pf(nbr / base_len, counter, base);
	write(1, &base[nbr % base_len], 1);
	(*counter)++;
}

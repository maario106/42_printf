/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:36:32 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/16 21:30:31 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_pf(unsigned int nbr, size_t *counter, char *base)
{
	ft_putnbr_base_pf(nbr, counter, base);
}

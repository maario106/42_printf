/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:55:45 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/16 20:55:45 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *counter)
{
	char	*nbr;
	size_t	len;

	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	write(1, nbr, len);
	(*counter) += len;
	free(nbr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:34:17 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/29 18:34:17 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putnchar_bonus(char c, int n, size_t *counter)
{
	while (n > 0)
	{
		write(1, &c, 1);
		(*counter)++;
		n--;
	}
}

void	ft_putdigits_bonus(uintptr_t n, char *base, size_t *counter)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putdigits_bonus(n / base_len, base, counter);
	write(1, &base[n % base_len], 1);
	(*counter)++;
}

int	ft_nbrlen_bonus(uintptr_t n, size_t base_len)
{
	int	len;

	len = 1;
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_get_base_bonus(char spec)
{
	if (spec == 'x' || spec == 'p')
		return (LOWER_HEX_BASE);
	if (spec == 'X')
		return (UPPER_HEX_BASE);
	return (DEC_BASE);
}

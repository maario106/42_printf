/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:07:55 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/05/27 12:13:04 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whitespace_and_get_sign(const char **str)
{
	int	neg;

	neg = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			neg *= -1;
		(*str)++;
	}
	return (neg);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	is_negative;

	if (!nptr || nptr[0] == '\0')
		return (0);
	nbr = 0;
	is_negative = skip_whitespace_and_get_sign(&nptr);
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (int)(*nptr - '0');
		nptr++;
	}
	return (nbr * is_negative);
}

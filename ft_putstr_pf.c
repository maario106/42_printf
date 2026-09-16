/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:55:47 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/16 21:12:30 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *s, size_t *counter)
{
	size_t	len;

	if (!s)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
	len = ft_strlen(s);
	write(1, s, len);
	(*counter) += len;
}

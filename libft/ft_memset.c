/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:24:24 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/04/20 16:25:05 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	block;
	size_t			counter;
	char			*ptr;	

	block = c;
	counter = 0;
	ptr = s;
	while (counter < n)
	{
		ptr[counter] = block;
		counter++;
	}
	return (s);
}

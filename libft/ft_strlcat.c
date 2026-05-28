/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:48:34 by codespace         #+#    #+#             */
/*   Updated: 2026/05/27 12:10:43 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	offset;

	src_len = ft_strlen(src);
	offset = 0;
	while (dst[offset] != '\0' && offset < size)
		offset++;
	if (size <= offset)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && i < size - offset - 1)
	{
		dst[offset + i] = src[i];
		i++;
	}
	dst[offset + i] = '\0';
	return (src_len + offset);
}

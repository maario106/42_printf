/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:14:15 by codespace         #+#    #+#             */
/*   Updated: 2026/05/27 12:40:19 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*ptr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// int main(void)
// {
// 	char	*result;

// 	// Test 1: uppercase
// 	result = ft_strmapi("hello world", to_upper);
// 	printf("Test 1 (uppercase): %s\n", result);
// 	free(result);

// 	// Test 2: add index (a→a, b+1→c, c+2→e, ...)
// 	result = ft_strmapi("abcdef", add_index);
// 	printf("Test 2 (add index): %s\n", result);
// 	free(result);

// 	// Test 3: NULL string
// 	result = ft_strmapi(NULL, to_upper);
// 	printf("Test 3 (NULL): %s\n", result ? result : "(null)");

// 	// Test 4: empty string
// 	result = ft_strmapi("", to_upper);
// 	printf("Test 4 (empty): [%s]\n", result);
// 	free(result);

// 	return (0);
// }
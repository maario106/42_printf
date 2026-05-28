/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:15:07 by codespace         #+#    #+#             */
/*   Updated: 2026/05/27 12:10:36 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// // Cambia minúsculas a mayúsculas modificando in place
// void	to_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c -= 32;
// }

// // Suma el índice al valor del carácter
// void	add_index(unsigned int i, char *c)
// {
// 	*c += i;
// }

// // Reemplaza vocales por '*'
// void	mask_vowels(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c == 'a' || *c == 'e' || *c == 'i' || *c == 'o' || *c == 'u')
// 		*c = '*';
// }

// int main(void)
// {
// 	char	str1[] = "hello world";
// 	char	str2[] = "abcdef";
// 	char	str3[] = "programming is fun";
// 	char	empty[] = "";

// 	// Test 1: uppercase
// 	ft_striteri(str1, to_upper);
// 	printf("Test 1 (uppercase): %s\n", str1);

// 	// Test 2: add index
// 	ft_striteri(str2, add_index);
// 	printf("Test 2 (add index): %s\n", str2);

// 	// Test 3: mask vowels
// 	ft_striteri(str3, mask_vowels);
// 	printf("Test 3 (mask vowels): %s\n", str3);

// 	// Test 4: empty string
// 	ft_striteri(empty, to_upper);
// 	printf("Test 4 (empty): [%s]\n", empty);

// 	// Test 5: NULL
// 	ft_striteri(NULL, to_upper);
// 	printf("Test 5 (NULL): no crash\n");

// 	return (0);
// }
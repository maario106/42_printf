/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:34:17 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/29 18:34:17 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	process_bonus(va_list *vargs, t_fmt *f, size_t *counter)
{
	if (f->spec == 'c')
		ft_print_char_bonus(va_arg(*vargs, int), f, counter);
	else if (f->spec == 's')
		ft_print_str_bonus(va_arg(*vargs, char *), f, counter);
	else if (f->spec == 'p')
		ft_print_ptr_bonus(va_arg(*vargs, void *), f, counter);
	else if (f->spec == 'd' || f->spec == 'i')
		ft_print_int_bonus(va_arg(*vargs, int), f, counter);
	else if (f->spec == 'u' || f->spec == 'x' || f->spec == 'X')
		ft_print_uint_bonus(va_arg(*vargs, unsigned int), f, counter);
	else if (f->spec == '%')
		ft_putnchar_bonus('%', 1, counter);
}

int	ft_printf(char const *chain, ...)
{
	va_list	vargs;
	size_t	counter;
	t_fmt	f;

	if (!chain)
		return (0);
	counter = 0;
	va_start(vargs, chain);
	while (*chain != '\0')
	{
		if (*chain == '%')
		{
			chain++;
			ft_parse_bonus(&chain, &f);
			process_bonus(&vargs, &f, &counter);
		}
		else
			ft_putnchar_bonus(*chain, 1, &counter);
		if (*chain != '\0')
			chain++;
	}
	va_end(vargs);
	return (counter);
}

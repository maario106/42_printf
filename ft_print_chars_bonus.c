/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:34:17 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/29 18:34:17 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_char_bonus(char c, t_fmt *f, size_t *counter)
{
	if (!f->minus)
		ft_putnchar_bonus(' ', f->width - 1, counter);
	ft_putnchar_bonus(c, 1, counter);
	if (f->minus)
		ft_putnchar_bonus(' ', f->width - 1, counter);
}

/*
** Como glibc: un NULL se imprime "(null)" solo si cabe entero en la precisión.
*/
void	ft_print_str_bonus(char *s, t_fmt *f, size_t *counter)
{
	int	len;

	if (!s && f->prec >= 0 && f->prec < 6)
		s = "";
	else if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (f->prec >= 0 && f->prec < len)
		len = f->prec;
	if (!f->minus)
		ft_putnchar_bonus(' ', f->width - len, counter);
	write(1, s, len);
	(*counter) += len;
	if (f->minus)
		ft_putnchar_bonus(' ', f->width - len, counter);
}

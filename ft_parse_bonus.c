/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:34:17 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/29 18:34:17 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_set_flag_bonus(char c, t_fmt *f)
{
	if (c == '-')
		f->minus = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '+')
		f->plus = 1;
}

static int	ft_read_number_bonus(char const **chain)
{
	int	n;

	n = 0;
	while (ft_isdigit(**chain))
	{
		n = n * 10 + (**chain - '0');
		(*chain)++;
	}
	return (n);
}

/*
** Lee %[flags][ancho][.precisión] y deja *chain apuntando a la letra
** de conversión, que se guarda en f->spec.
*/
void	ft_parse_bonus(char const **chain, t_fmt *f)
{
	ft_bzero(f, sizeof(t_fmt));
	f->prec = -1;
	while (**chain != '\0' && ft_strchr("-0# +", **chain))
	{
		ft_set_flag_bonus(**chain, f);
		(*chain)++;
	}
	f->width = ft_read_number_bonus(chain);
	if (**chain == '.')
	{
		(*chain)++;
		f->prec = ft_read_number_bonus(chain);
	}
	f->spec = **chain;
}

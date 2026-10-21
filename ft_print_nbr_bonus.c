/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:34:17 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/29 18:34:17 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_int_bonus(int n, t_fmt *f, size_t *counter)
{
	if (n < 0)
		ft_putnbr_bonus(-(long)n, "-", f, counter);
	else if (f->plus)
		ft_putnbr_bonus(n, "+", f, counter);
	else if (f->space)
		ft_putnbr_bonus(n, " ", f, counter);
	else
		ft_putnbr_bonus(n, "", f, counter);
}

void	ft_print_uint_bonus(unsigned int n, t_fmt *f, size_t *counter)
{
	if (f->hash && n != 0 && f->spec == 'x')
		ft_putnbr_bonus(n, "0x", f, counter);
	else if (f->hash && n != 0 && f->spec == 'X')
		ft_putnbr_bonus(n, "0X", f, counter);
	else
		ft_putnbr_bonus(n, "", f, counter);
}

void	ft_print_ptr_bonus(void *ptr, t_fmt *f, size_t *counter)
{
	if (!ptr)
	{
		f->prec = -1;
		ft_print_str_bonus("(nil)", f, counter);
	}
	else if (f->plus)
		ft_putnbr_bonus((uintptr_t)ptr, "+0x", f, counter);
	else if (f->space)
		ft_putnbr_bonus((uintptr_t)ptr, " 0x", f, counter);
	else
		ft_putnbr_bonus((uintptr_t)ptr, "0x", f, counter);
}

/*
** Ceros a la izquierda: los que pide la precisión o, si no hay precisión
** ni flag '-', los que faltan para llenar el ancho con el flag '0'.
*/
static int	ft_count_zeros_bonus(int plen, int digits, t_fmt *f)
{
	int	zeros;

	zeros = f->prec - digits;
	if (f->zero && !f->minus && f->prec < 0)
		zeros = f->width - plen - digits;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

/*
** Imprime [espacios][prefijo][ceros][dígitos][espacios].
** prefix es el signo o el 0x; los ceros salen de la precisión o del flag '0'.
*/
void	ft_putnbr_bonus(uintptr_t n, char *prefix, t_fmt *f, size_t *counter)
{
	char	*base;
	int		plen;
	int		digits;
	int		zeros;
	int		pad;

	base = ft_get_base_bonus(f->spec);
	plen = ft_strlen(prefix);
	digits = ft_nbrlen_bonus(n, ft_strlen(base));
	if (n == 0 && f->prec == 0)
		digits = 0;
	zeros = ft_count_zeros_bonus(plen, digits, f);
	pad = f->width - plen - zeros - digits;
	if (!f->minus)
		ft_putnchar_bonus(' ', pad, counter);
	write(1, prefix, plen);
	(*counter) += plen;
	ft_putnchar_bonus('0', zeros, counter);
	if (digits > 0)
		ft_putdigits_bonus(n, base, counter);
	if (f->minus)
		ft_putnchar_bonus(' ', pad, counter);
}

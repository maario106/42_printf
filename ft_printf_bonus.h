/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 18:34:17 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/29 18:34:17 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

# define DEC_BASE "0123456789"
# define UPPER_HEX_BASE "0123456789ABCDEF"
# define LOWER_HEX_BASE "0123456789abcdef"

/*
** Una especificación de conversión ya parseada: %[flags][ancho][.precisión]spec
** prec vale -1 cuando no se ha indicado precisión.
*/
typedef struct s_fmt
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		prec;
	char	spec;
}	t_fmt;

int		ft_printf(char const *chain, ...);
void	ft_parse_bonus(char const **chain, t_fmt *f);
void	ft_print_char_bonus(char c, t_fmt *f, size_t *counter);
void	ft_print_str_bonus(char *s, t_fmt *f, size_t *counter);
void	ft_print_int_bonus(int n, t_fmt *f, size_t *counter);
void	ft_print_uint_bonus(unsigned int n, t_fmt *f, size_t *counter);
void	ft_print_ptr_bonus(void *ptr, t_fmt *f, size_t *counter);
void	ft_putnbr_bonus(uintptr_t n, char *prefix, t_fmt *f, size_t *counter);
void	ft_putnchar_bonus(char c, int n, size_t *counter);
void	ft_putdigits_bonus(uintptr_t n, char *base, size_t *counter);
int		ft_nbrlen_bonus(uintptr_t n, size_t base_len);
char	*ft_get_base_bonus(char spec);

#endif

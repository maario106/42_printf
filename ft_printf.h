/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosas-n <mrosas-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 20:36:38 by mrosas-n          #+#    #+#             */
/*   Updated: 2026/09/16 21:47:21 by mrosas-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "libft/libft.h"

# define DEC_BASE "0123456789"
# define UPPER_HEX_BASE "0123456789ABCDEF"
# define LOWER_HEX_BASE "0123456789abcdef"

int		ft_printf(char const *chain, ...);
void	process(va_list vargs, char *chain, size_t *counter);
void	ft_putchar_pf(char c, size_t *counter);
void	ft_putstr_pf(char *s, size_t *counter);
void	ft_putnbr_pf(int n, size_t *counter);
void	ft_putunbr_pf(unsigned int n, size_t *counter);
void	ft_putptr_pf(void *ptr, size_t *counter);
void	ft_puthex_pf(unsigned int nbr, size_t *counter, char *base);
void	ft_putnbr_base_pf(uintptr_t nbr, size_t *counter, char *base);

#endif
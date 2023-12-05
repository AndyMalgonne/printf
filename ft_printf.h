/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:34:49 by amalgonn          #+#    #+#             */
/*   Updated: 2023/12/04 12:44:17 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *input, ...);
int	print_char(char c);
int	print_string(char *s);
int	print_num(int nb);
int	putnbr_base(unsigned long nbr, char *base);
int	print_ptr(unsigned long nbr, char *base);

#endif

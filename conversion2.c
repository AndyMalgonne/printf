/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:10:58 by amalgonn          #+#    #+#             */
/*   Updated: 2023/11/28 16:47:22 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int				size_base;
	int				i;

	size_base = 0;
	while (base[size_base])
		size_base++;
	if (nbr)
	{
		i = ft_putnbr_base(nbr / size_base, base);
		ft_putchar_fd(base[nbr % size_base], 1);
		return (i + 1);
	}
	return (0);
}

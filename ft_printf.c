/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalgonn <amalgonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:49:11 by amalgonn          #+#    #+#             */
/*   Updated: 2023/11/28 16:43:39 by amalgonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(const char *input, va_list arg)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += print_char(va_arg(arg, int));
	else if (*input == 's')
		i += print_string(va_arg(arg, char *));
	// else if (*input == 'p')
	// 	i += print_ptr(va_arg(arg, unsigned long));
	else if (*input == 'd' || *input == 'i')
		i += print_num(va_arg(arg, int));
	else if (*input == 'u')
		i += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	else if (*input == 'x')
		i += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (*input == 'X')
		i += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start (args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
			i += check_type(input, args);
			else if (*input == '%')
			i += print_char('%');
		}
		else
		i += print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}


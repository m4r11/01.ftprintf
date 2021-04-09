/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:57:54 by user              #+#    #+#             */
/*   Updated: 2021/04/09 15:07:27 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_ftoa(char *input, int index, int has_format, va_list args2)
{
	signed long int	decipart;
	signed long int	intpart;
	double			f;

	if (has_format == -1)
	{
		f = va_arg(args2, double);
		if (f < 0)
		{
			ft_putc('-');
			f *= -1;
		}
		intpart = (signed long int)f;
		ft_putnbr(intpart);
		ft_putc('.');
		f -= intpart;
		f *= 1000000;
		decipart = (signed long int)(f + 0.5);
		ft_putnbr(decipart);
	}
	return (ft_intstrchr_flag(input, 'f', index));
}

int	conv_fetoa(char *input, int index, int has_format, va_list args2)
{
	double			f;
	signed long int	decipart;
	signed long int	intpart;

	if (has_format == -1)
	{
		f = va_arg(args2, double);
		if (f < 0)
		{
			ft_putc('-');
			f *= -1;
		}
		intpart = (signed long int)f;
		ft_putnbr(intpart);
		ft_putc('.');
		f -= intpart;
		f *= 1000000;
		decipart = (signed long int)(f + 0.5);
		ft_putnbr(decipart);
		ft_putstr("e+");
	}
	return (ft_intstrchr_flag(input, 'e', index));
}

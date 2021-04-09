/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:34:39 by user              #+#    #+#             */
/*   Updated: 2021/04/09 13:02:47 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_n(char *input, int index, int has_format, va_list args2)
{
	int n;
	int c;
	if (has_format == -1)
	{
		c = va_arg(args2, int);
		n = ft_intlen(c);
	}
	return (ft_intstrchr_flag(input, 'n', index));
}

int conv_otoa(char *input, int index, int has_format, va_list args2)
{
	int o;

	if (has_format == -1)
	{
		o = va_arg(args2, int);
		ft_putnbr(o);
	}
	return (ft_intstrchr_flag(input, '0', index));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_fge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:57:54 by user              #+#    #+#             */
/*   Updated: 2021/03/24 11:59:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_ftoa(char *input, int has_format, va_list args2)
{
    double f;
    signed long int decipart;
    signed long int intpart;

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
    f *= 1000000;                          //upto 6 decimal points
    decipart = (signed long int)(f + 0.5); //+0.5 to round of the value
    ft_putnbr(decipart);
}

void conv_fetoa(char *input, int has_format, va_list args2)
{
    double f;
    signed long int decipart;
    signed long int intpart;

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
    f *= 1000000;                          //upto 6 decimal points
    decipart = (signed long int)(f + 0.5); //+0.5 to round of the value
    ft_putnbr(decipart);
    ft_putstr("e+");
}
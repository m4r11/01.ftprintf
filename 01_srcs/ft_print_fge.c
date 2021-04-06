/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:57:54 by user              #+#    #+#             */
/*   Updated: 2021/04/05 19:14:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int conv_ftoa(char *input,int index, int has_format, va_list args2)
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

    return(ft_intstrchr_flag(input, 'f', index));
}

int conv_fetoa(char *input,int index, int has_format, va_list args2)
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
    return(ft_intstrchr_flag(input, 'e', index));
}
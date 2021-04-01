/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cdiu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:54:44 by user              #+#    #+#             */
/*   Updated: 2021/04/01 08:52:29 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_c(char *input, int has_format, va_list args2)
{
    int print;
    if (has_format == -1)
    {
        print = va_arg(args2, int);
        ft_putc(print);
    }
    else 
        return ;
}

void conv_itoa(char *input, int has_format, va_list args2)
{
    signed int x;
    if (has_format == -1)
    {
        x = va_arg(args2, signed int);
        ft_putnbr(x);
    }
    else 
        return ;
}


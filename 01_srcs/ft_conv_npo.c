/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_npo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:00:12 by user              #+#    #+#             */
/*   Updated: 2021/03/28 14:14:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_n(char *input, int has_format, va_list args2)
{
    ft_putc('n');
}

void print_ptr(char *input, int has_format, va_list args2)
{
    long *print;

    if (has_format == -1)
    {
        print = va_arg(args2, long *);
        ft_put_address(input, print);
    }  
    return;
}

void conv_otoa(char *input, int has_format, va_list args2)
{
    ft_putc('8');
return ;
}
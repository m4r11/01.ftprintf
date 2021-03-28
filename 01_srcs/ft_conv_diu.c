/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_diu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:54:44 by user              #+#    #+#             */
/*   Updated: 2021/03/28 15:43:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void conv_uitoa(char *input, int has_format, va_list args2)
{
    int x;
    x = va_arg(args2, int);
    ft_putnbr(x);
}
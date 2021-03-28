/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hex_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:26:13 by user              #+#    #+#             */
/*   Updated: 2021/03/28 16:24:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_put_address(char *input, long *print)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;
    char *longmin;
    char *ulongmax;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    if (print == (long*)LONG_MIN)
    {
        longmin = "0x8000000000000000";
        ft_putstr(longmin);
        free(hexadecimal);
        return ;
    }
    if (print == (long*)ULONG_MAX)
    {
        ulongmax = "0xffffffffffffffff";
        ft_putstr(ulongmax);
        free(hexadecimal);
        return ;
    }
    quotient = *(long *)&print;
    ft_putc('0');
    ft_putc('x');
    if (quotient == 0)
        ft_putc('0');
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    free(hexadecimal);
    return;
}

int ft_hexlen(long *print)
{
    long decimal;
    long quotient;
    long remainder;
    char hexadecimal[20];
    //debug_number(print, "print");
    if (print == 0)
        return(3);
    int j = 0;
    quotient = *(long *)&print;
    if (quotient == 0)
    {
        hexadecimal[0] = '0';
        j += 1;
    }
    else
    {
        hexadecimal[0] = '0';
        hexadecimal[1] = 'x';
        j += 2;
    }
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    return (j);
}
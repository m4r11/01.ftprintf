/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:45:41 by user              #+#    #+#             */
/*   Updated: 2021/04/05 11:34:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_put_x(long print, int flag)
{
    long quotient;
    long remainder;
    char hexadecimal[100];
    char *longmin;
    int j = 0;
    if (print == LONG_MIN || print == ULONG_MAX)
    {
        if(flag == 3)
            longmin = "FFFFFFFF";
        if(flag == 2)
            longmin = "ffffffff";
        ft_putstr(longmin);
        return;
    }
    if (print == 0)
        ft_putc('0');
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
        {
            quotient = UINT_MAX - ((print * -1) - 1);
        }
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- > 0)
    {
        if(flag == 3)
            ft_putc(hexadecimal[j]);
        if(flag == 2)
            ft_putc(ft_tolower(hexadecimal[j]));
    }
    return;
}


void ft_put_x_up(long print, int min_c, int flag)
{
    long quotient;
    long remainder;
    char hexadecimal[20];
    char *ulongmax;
    int len;
    int j = 0;
    if (print == ULONG_MAX || print == LONG_MIN)
    {
        if(flag == 3)
            ulongmax = "FFFFFFFF";
        if(flag == 2)
            ulongmax = "ffffffff";
        if (min_c > 0)
            print_x_times(min_c - (ft_strlen(ulongmax)), '0');
        ft_putstr(ulongmax);
        return;
    }
    if (print == 0)
    {
        ft_putc('0');
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 1, '0');
        return;
    }
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
            quotient = UINT_MAX - ((print * -1) - 1);
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    len = ft_is_hex(hexadecimal);
    if (min_c > 0 && print != 0)
    {
        if (ft_intlen(print) == 1)
            print_x_times(min_c - 1, '0');
        else
            print_x_times(min_c - ft_xlen(print), '0');
    }
    while (j-- > 0)
    {
        if (flag == 2)
            ft_putc(ft_tolower(hexadecimal[j]));
        if (flag == 3)
            ft_putc(hexadecimal[j]);
    }
    return;
}
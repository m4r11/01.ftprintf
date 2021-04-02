/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/04/02 19:32:18 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_xtoa(char *input, int has_format, va_list args2)
{
    long q;
    if (has_format == -1)
    {
        q = va_arg(args2, int);
        ft_put_x(q);
        return;
    }
    return;
}

void conv_Xtoa(char *input, int has_format, va_list args2)
{
    long q;
    if (has_format == -1)
    {
        q = va_arg(args2, int);
        ft_put_X(q);
        return;
    }
    return;
}

void ft_put_x(long print)
{
    long quotient;
    long remainder;
    char hexadecimal[100];
    char *longmin;
    char *ulongmax;
    int j = 0;
    if (print == LONG_MIN)
    {
        longmin = "ffffffff";
        ft_putstr(longmin);
        return;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "ffffffff";
        ft_putstr(ulongmax);
        return;
    }
    if (print == 0)
        ft_putc('0');
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
        {  
/*             if((quotient *= -1) > 100)
                 quotient = quotient / 100;
            else 
                quotient = quotient / 10;
            print_x_times(quotient / 2, 'f'); */
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
        ft_putc(ft_tolower(hexadecimal[j]));
    return;
}
void ft_put_X(long print)
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
    if (print == LONG_MIN)
    {
        longmin = "0x8000000000000000";
        ft_putstr(longmin);
        free(hexadecimal);
        return;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "0xffffffffffffffff";
        ft_putstr(ulongmax);
        free(hexadecimal);
        return;
    }
    quotient = print;
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

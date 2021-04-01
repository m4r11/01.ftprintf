/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/04/01 18:57:45 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_xtoa(char *input, int has_format, va_list args2)
{
    long q;
    if(has_format == -1)
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
    if(has_format == -1)
    {
        q = va_arg(args2, int);
        ft_put_X(q);
        return;
    }
    return;
}

void ft_put_x(long print)
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
        longmin = "ffffffff";
        ft_putstr(longmin);
        free(hexadecimal);
        return ;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "ffffffff";
        ft_putstr(ulongmax);
        free(hexadecimal);
        return ;
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
        return ;
    }
    if (print == ULONG_MAX)
    {
        ulongmax = "0xffffffffffffffff";
        ft_putstr(ulongmax);
        free(hexadecimal);
        return ;
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

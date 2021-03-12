/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:56 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/11 16:00:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_itoa(char *formatting, va_list args2)
{
    int x;
    x = va_arg(args2, int);
    ft_putnbr(x);
}
void conv_xtoa(char *formatting, va_list args2)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    quotient = va_arg(args2, int);
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
    while (j-- >0)
        ft_putc(ft_tolower(hexadecimal[j]));
    return;
}

void conv_Xtoa(char *formatting, va_list args2)
{
    long decimal;
    long quotient;
    long remainder;
    char *hexadecimal;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    quotient = va_arg(args2, int);
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- >= 0)
        ft_putc(hexadecimal[j]);
    free(hexadecimal);
    return;
}
void conv_uitoa(char *formatting, va_list args2)
{
    int x;
    x = va_arg(args2, int);
    ft_putnbr(x);
}
void conv_ftoa(char *formatting, va_list args2)
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
void conv_fetoa(char *formatting, va_list args2)
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

void print_str(char *formatting, va_list args2)
{
    char *print;
    print = va_arg(args2, char *);
    ft_putstr(print);
}

void print_c(char *formatting, va_list args2)
{
    char print;
    print = va_arg(args2, int);
    ft_putc(print);
}

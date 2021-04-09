/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zconvs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:01:13 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:03:34 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr(int nb)
{
    //debug_number(nb, "nb");
    if (nb <= INT_MAX && nb >= INT_MIN)
    {
        if (nb == INT_MIN)
        {
            ft_putc('-');
            ft_putc('2');
            ft_putnbr(147483648);
        }
        else if (nb < 0)
        {
            ft_putc('-');
            ft_putnbr(-nb);
        }
        else if (nb > 9)
        {
            ft_putnbr(nb / 10);
            ft_putnbr(nb % 10);
        }
        else
            ft_putc(nb + '0');
    }
    return;
}

void ft_putnbr_u(unsigned int nb)
{
    if (nb <= UINT_MAX)
    {
        if (nb == UINT_MAX)
        {
            ft_putc('4');
            ft_putc('2');
            ft_putnbr(94967295);
            return ;
        }

        else if (nb < 0)
        {
            ft_putc('-');
            ft_putnbr_u(-nb);
        }
        else if (nb > 9)
        {
            ft_putnbr_u(nb / 10);
            ft_putnbr_u(nb % 10);
        }
        else
            ft_putc(nb + '0');
    }
    return;
}

void ft_putnbr_u_up(unsigned nb, int min_c)
{
    char *uintmax;

    if (nb < 0)
        nb = UINT_MAX;
    if (nb <= UINT_MAX)
    {
        if (nb == UINT_MAX)
        {
            uintmax = "4294967295";
            if (min_c > 0)
                print_x_times(min_c - ft_strlen(uintmax), '0');
            ft_putstr(uintmax);
            return;
        }
            print_x_times(min_c -ft_u_intlen(nb), '0');
        if (nb > 9)
        {
            ft_putnbr_u(nb / 10);
            ft_putnbr_u(nb % 10);
        }
        else
            ft_putc(nb + '0');
    }
    return;
}

void ft_put_x(long print, int flag)
{
    long quotient;
    long remainder;
    char hexadecimal[100];
    char *longmin;
    int j = 0;
    if (print == (long)LONG_MIN || print == (long)ULONG_MAX)
    {
        if (flag == 3)
            longmin = "FFFFFFFF";
        if (flag == 2)
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
        if (flag == 3)
            ft_putc(hexadecimal[j]);
        if (flag == 2)
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
    if (print == (long)ULONG_MAX || print == (long)LONG_MIN)
    {
        if (flag == 3)
            ulongmax = "FFFFFFFF";
        if (flag == 2)
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
    /*     if (print == 10)
    {
        if (min_c > 0 && print == 10)
            print_x_times(min_c - 1, '0');
        ft_putc('a');
        return;
    } */
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
    //debug_str(hexadecimal, "he");
    while (j-- > 0)
    {
        if (flag == 2)
            ft_putc(ft_tolower(hexadecimal[j]));
        if (flag == 3)
            ft_putc(hexadecimal[j]);
    }
    return;
}


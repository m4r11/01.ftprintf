/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:38:53 by user              #+#    #+#             */
/*   Updated: 2021/04/06 11:14:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int type_print(unsigned int print, int to_pad, int min_c, int size, int zero)
{
    if (to_pad > 0)
    {
        if (min_c > to_pad)
            to_pad = min_c;
        if (min_c == 0 && zero == 1)
        {
            if (print == 0)
            {
                print_x_times(to_pad, ' ');
                 return(0);
            }
            print_x_times(to_pad - ft_u_intlen(print), ' ');
            ft_putnbr_u_up(print, min_c);
            return (0);
        }
        if (min_c == 0 && zero == -3)
        {
            if (print == 0)
            {
                print_x_times(to_pad, ' ');
                return (0);
            }
            print_x_times(to_pad - ft_u_intlen(print), ' ');
            ft_putnbr_u_up(print, min_c);
            return (0);
        }
        if(min_c == -1 && zero == 1)
        {
            print_x_times((to_pad ) - ft_u_intlen(print), '0');
            ft_putnbr_u_up(print, min_c);
            return(0);
        }
        if (to_pad > min_c)
        {
            if(min_c < ft_u_intlen(print))
                print_x_times(to_pad - ft_u_intlen(print), ' ');
            else 
                print_x_times(to_pad - min_c, ' ');
            ft_putnbr_u_up(print, min_c);
            return (0);
        }
        print_x_times(min_c - to_pad, ' ');
        ft_putnbr_u_up(print, min_c);
        return (0);
    }
    if (to_pad < 0)
    {
        if (min_c == 0 && print != 0)
        {
            ft_putnbr_u_up(print, min_c);
            print_x_times((to_pad * -1) - ft_u_intlen(print), ' ');
            return (0);
        }
        if (min_c == 0 && print == 0)
        {
            print_x_times((to_pad * -1), ' ');
            return (0);
        }
        if (min_c > 0 && print == 0)
        {
            to_pad *= -1;
            ft_putnbr_u_up(print, min_c);
            if (min_c < ft_u_intlen(print))
                print_x_times(to_pad - ft_u_intlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c < ft_u_intlen(print))
        {
            ft_putnbr_u_up(print, min_c);
            print_x_times((to_pad * -1) - ft_u_intlen(print), ' ');
            return (0);
        }
        ft_putnbr_u_up(print, min_c);
        print_x_times((to_pad * -1) - min_c, ' ');
        return (0);
    }
    if (to_pad == 0 && min_c == 0 && print != 0)
        ft_putnbr_u_up(print, min_c);
    if (to_pad == 0 && min_c > 0)
        ft_putnbr_u_up(print, min_c);
    return (0);
}

int conv_uitoa(char *input, int index, int has_format, va_list args2)
{
    /* unsigned int x; */
    unsigned int a;
    int width;
    int min_c;
    int zero;
    if (has_format == -1)
    {
        a = va_arg(args2, unsigned int);
        ft_putnbr(a);
        return(ft_intstrchr_flag(input, 'u', index));
    }
    else
    {
        width = find_width(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        zero = ft_zerochr(input, index);
        a = va_arg(args2, unsigned int);
        type_print(a, width, min_c, ft_u_intlen(a), zero);
        return(ft_intstrchr_flag(input, 'u', index));
    }
    return(FAIL);
}

void ft_putnbr_u_up(unsigned nb, int min_c)
{
    int len;
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
        len = ft_u_intlen(nb);
        if (min_c > 0)
        {
            if (ft_u_intlen(nb) == 1)
                print_x_times(min_c - 1, '0');
            else
                print_x_times(min_c - len, '0');
        }
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
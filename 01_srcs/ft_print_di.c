/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:49:12 by user              #+#    #+#             */
/*   Updated: 2021/04/08 15:19:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pad_left_ints(int print, int to_pad, int min_c, int zero)
{
    if (min_c == 0 && print != 0)
    {
        print_x_times(to_pad - ft_intlen(print), ' ');
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (min_c == 0 && print == 0)
    {
        print_x_times(to_pad, ' ');
        return (0);
    }
    if (min_c == -1 && zero == -3)
    {
        if (print == 0)
        {
            if (to_pad >= 1)
            {
                print_x_times(to_pad - 1, ' ');
                ft_putc('0');
                return (0);
            }
            print_x_times(to_pad, ' ');
            return (0);
        }
        print_x_times(to_pad - ft_intlen(print), ' ');
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (min_c == -1 && zero == 1)
    {
        if (print == 0)
            print_x_times(to_pad, '0');
        else
        {
            min_c = to_pad;
            if (print < 0)
                min_c -= 1;
            ft_putnbr_up(print, min_c);
        }
        return (0);
    }
    if (zero == 1)
    {
        {
            if (print < 0 && ft_intlen(print) <= min_c)
                to_pad -= 1;
            if (min_c < ft_intlen(print))
                print_x_times(to_pad - ft_intlen(print), ' ');
            if (min_c >= ft_intlen(print))
                print_x_times(to_pad - min_c, ' ');
            ft_putnbr_up(print, min_c);
            return (0);
        }
    }
    if (to_pad <= min_c)
    {
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (min_c < to_pad && min_c > 0)
    {
        if (print == 0)
        {
            print_x_times(to_pad - min_c, ' ');
            ft_putnbr_up(print, min_c);
            return (0);
        }
        if (min_c < ft_intlen(print))
        {
            if (print < 0 && ft_intlen(print) < min_c)
                to_pad -= 1;
            print_x_times(to_pad - ft_intlen(print), ' ');
            ft_putnbr_up(print, min_c);
            return (0);
        }
        if (min_c < ft_intlen(print) && print > 0)
        {
            print_x_times(to_pad - ft_intlen(print), ' ');
            ft_putnbr_up(print, min_c);
            return (0);
        }
        else
        {
            if (print < 0)
                print_x_times(to_pad - min_c - 1, ' ');
            else
                print_x_times(to_pad - min_c, ' ');
        }
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (min_c == 0 && print == 0)
        print_x_times(to_pad, ' ');
    return (0);
    if (to_pad > min_c)
    {
        if (print < 0)
            print_x_times(to_pad - min_c - 1, ' ');
        else
            print_x_times(to_pad - min_c, ' ');
        ft_putnbr_up(print, min_c);
        return (0);
    }
    if (min_c > to_pad)
        to_pad = min_c;
    print_x_times(min_c - to_pad, ' ');
    ft_putnbr_up(print, min_c);
}

int pad_right_ints(int print, int to_pad, int min_c, int zero)
{
    if (min_c == 0 && print != 0)
    {
        ft_putnbr_up(print, min_c);
        print_x_times((to_pad * -1) - ft_intlen(print), ' ');
        return (0);
    }
    if (min_c == -1 && print == 0)
    {
        if (zero != -1 && print < 0)
        {
            min_c = to_pad;
            ft_putnbr_up(print, min_c);
            return (0);
        }
        ft_putnbr_up(print, min_c);
        print_x_times((to_pad * -1) - 1, ' ');
        return (0);
    }
    if (min_c == 0 && print == 0)
    {
        /* this will ruin other stuff */
        print_x_times((to_pad * -1), ' ');
        return (0);
    }
    if (min_c < ft_intlen(print))
    {
        ft_putnbr_up(print, min_c);
        print_x_times((to_pad * -1) - ft_intlen(print), ' ');
        return (0);
    }
    ft_putnbr_up(print, min_c);
    if (print < 0)
        print_x_times((to_pad * -1) - min_c - 1, ' ');
    else
        print_x_times((to_pad * -1) - min_c, ' ');
    return (0);
}

int format_ints(int print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
        return (pad_left_ints(print, to_pad, min_c, zero));
    if (to_pad <= 0)
        return (pad_right_ints(print, to_pad, min_c, zero));
    if (to_pad == 0 && min_c > 0)
        ft_putnbr_up(print, min_c);
    if (to_pad == 0 && min_c == 0) // && print == '0')
        ft_putnbr_up(print, min_c);
    return (0);
}

int conv_itoa(char *input, int index, int has_format, va_list args2)
{
    signed int x;
    int width;
    int min_c;
    int zero;

    width = 0;
    if (has_format == -1)
    {
        x = va_arg(args2, signed int);
        ft_putnbr(x);
        return (ft_intstrchr_flag(input, 'i', index));
    }
    else
    {
        width = find_width_d(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        zero = ft_zerochr(input, index);
        /*         debug_number(width, "w");
        debug_number(min_c, "m");
        debug_number(zero, "z"); */
        x = va_arg(args2, int);
        format_ints(x, width, min_c, zero);
        return (ft_intstrchr_flag(input, 'i', index));
    }
    return (FAIL);
}

int conv_dtoa(char *input, int index, int has_format, va_list args2)
{
    signed int x;
    int width;
    int min_c;
    int zero;
    //debug_number(index, "index");
    if (has_format == -1)
    {
        x = va_arg(args2, signed int);
        ft_putnbr(x);
        return (ft_intstrchr_flag(input, 'd', index));
    }
    else
    {
        width = find_width(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        zero = ft_zerochr(input, index);
        /*         debug_number(zero, "z");
        debug_number(min_c, "m");
        debug_number(width, "w"); */
        x = va_arg(args2, int);
        format_ints(x, width, min_c, zero);
        return (ft_intstrchr_flag(input, 'd', index));
    }
    return (FAIL);
}

void ft_putnbr_up(int print, int min_c)
{
    int len;
    char *intmin;
    if (print <= INT_MAX && print >= INT_MIN)
    {
        if (print < 0)
        {
            print *= -1;
            ft_putc('-');
        }
        if (print == INT_MIN)
        {
            intmin = "2147483648";
            ft_putstr(intmin);
            if (min_c > 0)
                print_x_times(min_c - ft_strlen(intmin), '0');
            return;
        }
        len = ft_intlen(print);
        if (min_c > 0 && print == 0)
        {
            print_x_times(min_c, '0');
            return;
        }
        if (min_c > 0 && print != 0)
        {
            if (ft_intlen(print) == 1)
                print_x_times(min_c - 1, '0');
            else
                print_x_times(min_c - len, '0');
        }
        if (print > 9)
        {
            ft_putnbr(print / 10);
            ft_putnbr(print % 10);
        }
        else
            ft_putc(print + '0');
    }
    return;
}
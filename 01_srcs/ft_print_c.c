/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:54:44 by user              #+#    #+#             */
/*   Updated: 2021/04/05 19:09:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pad_right_c(int print, int to_pad, int min_c, int zero)
{
    if (min_c == 0)
    {
        print_x_times(to_pad - 1, ' ');
        ft_putc(print);
        return (0);
    }
    if (min_c == 0 && zero == -1)
    {
        if (print == 0)
        {
            print_x_times(to_pad, ' ');
            return (0);
        }
        print_x_times(to_pad - 1, ' ');
        ft_putc(print);
        return (0);
    }
    if (to_pad > min_c)
    {
        if (min_c == -1)
            print_x_times(to_pad - 1, ' ');
        else
            print_x_times(to_pad - min_c, ' ');
        ft_putc(print);
        return (0);
    }
    if (min_c > to_pad)
        to_pad = min_c;
    print_x_times(min_c - to_pad, ' ');
    ft_putc(print);
    return (0);
}

int pad_left_c(int print, int to_pad, int min_c, int zero)
{
    if (min_c == 0 && print != 0)
    {
        ft_putc(print);
        print_x_times((to_pad * -1) - 1, ' ');
        return (0);
    }
    if (min_c == 0 && print == 0)
    {
        /* this will ruin other stuff */
        ft_putc(print);
        print_x_times((to_pad * -1) - 1, ' ');
        return (0);
    }
    if (min_c == -1)
    {
        ft_putc(print);
        print_x_times((to_pad * -1) - 1, ' ');
        return (0);
    }
    if (min_c > 0 && print == 0)
    {
        print_x_times(min_c, '0');
        return (0);
    }
    if (min_c < ft_xlen(print))
    {
        ft_putc(print);
        print_x_times((to_pad * -1) - ft_xlen(print), ' ');
        return (0);
    }
    ft_putc(print);
    print_x_times((to_pad * -1) - min_c, ' ');
    return (0);
}

int format_c(int print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
        return (pad_right_c(print, to_pad, min_c, zero));
    if (to_pad < 0)
        return(pad_left_c(print, to_pad, min_c, zero));
    if (to_pad == 0 && min_c > 0)
        ft_putc(print);
    if (to_pad == 0 && min_c <= 0) // && print == '0')
        ft_putc(print);
    return (0);
}

int print_c(char *input, int index, int has_format, va_list args2)
{
    int q;
    int width;
    int min_c;
    int zero;

    zero = ft_intstrchr(input, '0', index);
    if (has_format == -1)
    {
        q = va_arg(args2, int);
        ft_putc(q);
        return(ft_intstrchr_flag(input, 'c', index));
    }
    else
    {
        width = find_width_c(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        q = va_arg(args2, int);
        format_c(q, width, min_c, zero);
        return(ft_intstrchr_flag(input, 'c', index));
    }
    return(FAIL);
}

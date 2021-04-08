/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/04/08 14:10:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int format_x(t_dir_variables var)
{
    if (var.to_pad > 0)
    {
        if (var.has_zero == 1)
        {
            if (var.min_c == 0 && var.q == 0)
            {
                print_x_times(var.to_pad - ft_intlen(var.q) + 1, ' ');
                return (0);
            }
            if (var.min_c == -1 && var.q != 0)
            {
                if (var.min_c < ft_xlen(var.q))
                    print_x_times(var.to_pad - ft_xlen(var.q), '0');
                if (var.min_c > ft_xlen(var.q))
                    print_x_times(var.to_pad - var.min_c, '0');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.min_c == -1 && var.q == 0)
            {
                print_x_times(var.to_pad - 1, '0');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.min_c > 0 && var.q == 0)
            {
                print_x_times(var.to_pad - var.min_c, ' ');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.min_c > 0 && var.q != 0)
            {
                if (var.min_c < ft_xlen(var.q))
                {
                    print_x_times(var.to_pad - ft_xlen(var.q), ' ');
                    ft_put_x_up(var.q, var.min_c, var.flag);
                    return (0);
                }
                if (var.min_c > ft_xlen(var.q))
                {
                    print_x_times(var.to_pad - var.min_c, ' ');
                    ft_put_x_up(var.q, var.min_c, var.flag);
                    return (0);
                }
            }
            if (var.min_c == 0 && var.q != 0)
            {
                if (var.min_c < ft_xlen(var.q))
                {
                    print_x_times(var.to_pad - ft_xlen(var.q), ' ');
                    ft_put_x_up(var.q, var.min_c, var.flag);
                    return (0);
                }
                if (var.min_c > ft_xlen(var.q))
                {
                    print_x_times(var.to_pad - var.min_c, ' ');
                    ft_put_x_up(var.q, var.min_c, var.flag);
                    return (0);
                }
            }
            return (0);
        }
        if (var.min_c == 0 && var.has_zero == -3)
        {
            if (var.q == 0)
            {
                print_x_times(var.to_pad, ' ');
                return (0);
            }
            print_x_times(var.to_pad - ft_xlen(var.q), ' ');
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        if (var.min_c == -1 && var.has_zero == 1)
        {
            if (var.q == 0)
            {
                print_x_times((var.to_pad), '0');
                return (0);
            }
            print_x_times((var.to_pad) - ft_xlen(var.q), '0');
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        if (var.min_c == 0 && var.has_zero == 1)
        {

            if (var.q == 0)
            {
                print_x_times((var.to_pad), ' ');
                return (0);
            }
            print_x_times((var.to_pad) - ft_xlen(var.q), ' ');
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        if (var.to_pad > var.min_c && var.min_c > 0)
        {
            if (ft_xlen(var.q) == 1 && var.min_c > 1)
            {
                print_x_times(var.to_pad - var.min_c, ' ');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.q == 0)
            {
                print_x_times(var.to_pad - var.min_c, ' ');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.min_c < ft_xlen(var.q))
                print_x_times(var.to_pad - ft_xlen(var.q), ' ');
            else
                print_x_times(var.to_pad - var.min_c, ' ');
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        if (var.to_pad < var.min_c && var.min_c > 0)
        {
            if (ft_xlen(var.q) == 1 && var.min_c > 1)
            {
                print_x_times(var.min_c - var.to_pad, ' ');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.q == 0)
            {
                print_x_times(var.to_pad - var.min_c, ' ');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            if (var.min_c < ft_xlen(var.q))
                print_x_times(var.to_pad - ft_xlen(var.q), ' ');
            else
            {
                //ft_printf("here");
                print_x_times(var.to_pad - var.min_c, ' ');
                ft_put_x_up(var.q, var.min_c, var.flag);
                return (0);
            }
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        if (var.to_pad > 0 && var.min_c == -1 && var.q == 0)
        {
            print_x_times(var.to_pad - 1, ' ');
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        if (var.to_pad > 0 && var.min_c == -1 && var.q != 0)
        {
            print_x_times(var.to_pad - ft_xlen(var.q), ' ');
            ft_put_x_up(var.q, var.min_c, var.flag);
            return (0);
        }
        print_x_times(var.min_c - var.to_pad, ' ');
        ft_put_x_up(var.q, var.min_c, var.flag);
        return (0);
    }
    if (var.to_pad < 0)
    {
        if (var.min_c == 0 && var.q != 0)
        {
            //printf("PORRRAAAAAAAAAAA");
            ft_put_x_up(var.q, var.min_c, var.flag);
            print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
            return (0);
        }
        if (var.min_c == 0 && var.q == 0)
        {
            print_x_times((var.to_pad * -1), ' ');
            return (0);
        }
        if (var.min_c > 0 && var.q == 0)
        {
            var.to_pad *= -1;
            ft_put_x_up(var.q, var.min_c, var.flag);
            if (var.min_c < ft_intlen(var.q))
                print_x_times(var.to_pad - ft_intlen(var.q), ' ');
            else
                print_x_times(var.to_pad - var.min_c, ' ');
            return (0);
        }
        if (var.min_c > 0 && var.q != 0)
        {
            var.to_pad *= -1;
            ft_put_x_up(var.q, var.min_c, var.flag);
            if (var.min_c < ft_xlen(var.q))
                print_x_times(var.to_pad - ft_xlen(var.q), ' ');
            else
                print_x_times(var.to_pad - var.min_c, ' ');
            return (0);
        }
        if (var.min_c != -1 && var.min_c < ft_xlen(var.q))
        {
            ft_put_x_up(var.q, var.min_c, var.flag);
            if (ft_intlen(var.q) == 1)
                print_x_times((var.to_pad * -1) - 1, ' ');
            else
                print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
            return (0);
        }
        if (var.to_pad < 0 && var.min_c == -1 && var.q == 0)
        {
            ft_put_x_up(var.q, var.min_c, var.flag);
            print_x_times((var.to_pad * -1) - 1, ' ');
            return (0);
        }
        ft_put_x_up(var.q, var.min_c, var.flag);
        if (ft_intlen(var.q) == 1)
            print_x_times((var.to_pad * -1) - 1, ' ');
        if (ft_intlen(var.q) == 2)
            print_x_times((var.to_pad * -1) - 2, ' ');
        else
            print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
        return (0);
    }
    if (var.to_pad == 0 && var.min_c == 0 && var.q != 0)
        ft_put_x_up(var.q, var.min_c, var.flag);
    if (var.to_pad == 0 && var.min_c < 0)
    {
        ft_put_x_up(var.q, var.min_c, var.flag);
        return (0);
    }
    if (var.to_pad == 0 && var.min_c > 0)
        ft_put_x_up(var.q, var.min_c, var.flag);
    return (0);
}

int conv_xtoa(char *input, int index, int has_format, va_list args2)
{
    t_dir_variables var;

    var.has_zero = ft_zerochr(input, index);
    var.flag = 2;
    if (has_format == -1)
    {
        var.q = va_arg(args2, long);
        ft_put_x(var.q, var.flag);
        return (ft_intstrchr_flag(input, 'x', index));
    }
    else
    {
        var.to_pad = find_width(input, index, args2);
        var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        /*         debug_number(var.to_pad, "t");
        debug_number(var.min_c, "m");
        debug_number(var.has_zero, "z"); */
        /*         debug_number(var.has_zero, "z"); */
        var.q = va_arg(args2, int);
        //debug_number(ft_xlen(var.q), "len");
        format_x(var);
        return (ft_intstrchr_flag(input, 'x', index));
    }
    return (FAIL);
}

int conv_Xtoa(char *input, int index, int has_format, va_list args2)
{
    t_dir_variables var;

    var.flag = 3;
    var.has_zero = ft_zerochr(input, index);
    if (has_format == -1)
    {
        var.q = va_arg(args2, long);
        ft_put_x(var.q, var.flag);
        return (ft_intstrchr_flag(input, 'X', index));
    }
    else
    {
        var.to_pad = find_width(input, index, args2);
        var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        var.q = va_arg(args2, int);
        format_x(var);
        return (ft_intstrchr_flag(input, 'X', index));
    }
    return (FAIL);
}

/* 
int format_X(long print, int to_pad, min_c, int zero)
{
    if (to_pad > 0)
    {
        if (min_c > to_pad)
            to_pad = min_c;
        if (min_c <= 0 && zero != -1)
        {
            if (print == 0)
                print_x_times(to_pad - ft_intlen(print), '0');
            else
                print_x_times(to_pad - ft_xlen(print), '0');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (min_c == 0 && zero == -1)
        {

            if (print == 0)
            {
                print_x_times(to_pad, ' ');
                return (0);
            }
            print_x_times(to_pad - ft_xlen(print), ' ');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (min_c == -1 && zero != -1)
        {
            print_x_times((to_pad)-ft_xlen(print), '0');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (to_pad > min_c && min_c > 0)
        {
            if (ft_xlen(print) == 1 && min_c > 1)
            {
                print_x_times(to_pad - min_c, ' ');
                ft_put_x_up(print, min_c, 3);
                return (0);
            }
            if(print == 0)
            {
                print_x_times(to_pad -min_c, ' ');
                ft_put_x_up(print, min_c, 3);
                return (0);
            }
            if (min_c < ft_xlen(print))
                print_x_times(to_pad - ft_xlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        if (to_pad > 0 && min_c == -1 && print == 0)
        {
            print_x_times(to_pad - 1, ' ');
            ft_put_x_up(print, min_c, 3);
            return (0);
        }
        print_x_times(min_c - to_pad, ' ');
        ft_put_x_up(print, min_c, 3);
        return (0);
    }
    if (to_pad < 0)
    {
        if (min_c == 0 && print != 0)
        {
            ft_put_x_up(print, min_c, 3);
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
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
            ft_put_x_up(print, min_c, 3);
            if (min_c < ft_intlen(print))
                print_x_times(to_pad - ft_intlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c > 0 && print != 0)
        {
            to_pad *= -1;
            ft_put_x_up(print, min_c, 3);
            if (min_c < ft_xlen(print))
                print_x_times(to_pad - ft_xlen(print), ' ');
            else
                print_x_times(to_pad - min_c, ' ');
            return (0);
        }
        if (min_c != -1 && min_c < ft_xlen(print))
        {
            ft_put_x_up(print, min_c, 3);
            if (ft_intlen(print) == 1)
                print_x_times((to_pad * -1) - 1, ' ');
            else
                print_x_times((to_pad * -1) - ft_xlen(print), ' ');
            return (0);
        }
        if (to_pad < 0 && min_c == -1 && print == 0)
        {
            ft_put_x_up(print, min_c, 3);
            print_x_times((to_pad * -1) - 1, ' ');
            return (0);
        }
        ft_put_x_up(print, min_c, 3);
        if (ft_intlen(print) == 1)
            print_x_times((to_pad * -1) - 1, ' ');
        if (ft_intlen(print) == 2)
            print_x_times((to_pad * -1) - 2, ' ');
        else
            print_x_times((to_pad * -1) - ft_xlen(print), ' ');
        return (0);
    }
    if (to_pad == 0 && min_c == 0 && print != 0)
        ft_put_x_up(print, min_c, 3);
    if (to_pad == 0 && min_c > 0)
        ft_put_x_up(print, min_c, 3);
    return (0);
} */

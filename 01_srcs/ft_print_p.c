/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:00:12 by user              #+#    #+#             */
/*   Updated: 2021/04/05 19:15:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int pad_left_p(long print, int to_pad, int min_c, int zero)
{
    if (min_c > to_pad)
        to_pad = min_c;
    if (min_c == 0 && zero != -1)
        if (min_c == 0 && zero == -1)
        {
            if (print == 0)
            {
                ft_put_address_up(print, min_c, to_pad);
                print_x_times(to_pad - 3, ' ');
                return (0);
            }
            print_x_times(to_pad - ft_u_intlen(print), ' ');
            ft_put_address_up(print, min_c, to_pad);
            return (0);
        }
    if (to_pad > min_c)
    { /* unico a func patra ja */
        if (print == 0)
        {
            print_x_times(to_pad - 3, ' ');
            ft_put_address_up(print, min_c, to_pad);
            return (0);
        }
        if (print > 0)
        {
            print_x_times(to_pad - ft_hexlen(print), ' ');
            ft_put_address_up(print, min_c, to_pad);
            return (0);
        }
        ft_put_address_up(print, min_c, to_pad);
        print_x_times(to_pad - ft_u_intlen(print), ' ');
        return (0);
    }
    print_x_times(min_c - to_pad, ' ');
    ft_put_address_up(print, min_c, to_pad);
    return (0);
}

int pad_right_p(long print, int to_pad, int min_c, int zero)
{
    if (min_c == 0 && print != 0)
    {
        ft_put_address_up(print, min_c, to_pad);
        print_x_times((to_pad * -1) - ft_hexlen(print), ' ');
        return (0);
    }
    if (min_c == 0 && print == 0)
    {
        print_x_times((to_pad * -1), ' ');
        return (0);
    }
    if (min_c > 0 && print == 0)
    {
        print_x_times(min_c, '0');
        return (0);
    }
    if (min_c != -1 && min_c < ft_xlen(print))
    {
        ft_put_address_up(print, min_c, to_pad);
        print_x_times((to_pad * -1) - ft_xlen(print), ' ');
        return (0);
    }
    if (min_c == -1)
    {
        /* escrevei aqu */
        if (print == 0 || print == 1)
        {
            ft_put_address_up(print, min_c, to_pad);
            print_x_times((to_pad * -1) - 3, ' ');
            return (0);
        }
        if (print < 0)
        {
            ft_put_address_up(print, min_c, to_pad);
            print_x_times((to_pad * -1) - ft_u_intlen(print) - 1, ' ');
            return (0);
        }
        /* tasqui */
        ft_put_address_up(print, min_c, to_pad);
        print_x_times((to_pad * -1) - ft_hexlen(print), ' ');
        return (0);
    }
    ft_put_address_up(print, min_c, to_pad);
    print_x_times((to_pad * -1) - min_c, ' ');
    return (0);
}

int format_address(long print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
        return (pad_left_p(print, to_pad, min_c, zero));
    if (to_pad < 0)
        return (pad_right_p(print, to_pad, min_c, zero));
    if (to_pad == 0 && min_c > 0)
        ft_put_address_up(print, min_c, to_pad);
    else
        return (0);
    return (0);
}

int print_ptr(char *input, int index, int has_format, va_list args2)
{
    long q;
    int width;
    int min_c;
    int zero = ft_intstrchr(input, '0', index);

    if (has_format == -1)
    {
        q = va_arg(args2, long);
        ft_put_address(input, q);
        return(ft_intstrchr_flag(input, 'p', index));
    }
    else
    {
        width = find_width_p(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        q = va_arg(args2, int);
        format_address(q, width, min_c, zero);
        return(ft_intstrchr_flag(input, 'p', index));
    }
    return(FAIL);
}

void ft_put_address_up(long print, int min_c, int flag)
{
    long decimal;
    long quotient;
    long remainder;
    char hexadecimal[100];
    char *longmin;
    char *ulongmax;
    int len;
    int j = 0;

    if (print == 0)
    {
        ft_putstr("0x0");
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 3, '0');
        return;
    }
    if (print == 1)
    {
        ft_putstr("0x1");
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 3, '0');
        return;
    }
    if (print == LONG_MIN)
    {
        longmin = "0x8000000000000000";
        print_x_times(min_c - (ft_strlen(longmin)), '0');
        ft_putstr(longmin);
        return;
    }
    if (print == UINT_MAX + 1)
    {
        ft_putc(' ');
        return;
    }
    quotient = print;
    ft_putc('0');
    ft_putc('x');
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
    len = ft_is_hex(hexadecimal);
    if (min_c > 0 && print != 0)
    {
        if (ft_intlen(print) == 1)
            print_x_times(min_c - 1, '0');
        else
            print_x_times(min_c - len, '0');
    }
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    return;
}

/* char position_address(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%'));
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    if (dv.temp[1] == '*' && dv.temp[2] == 'p')
    {
        dv.converted = va_arg(args2, int);
        dv.hex = *(va_arg(args2, long *));
        {
            if (dv.converted < 0)
            {
                dv.converted *= -1;
                ft_put_address(dir, &dv.hex);
                print_x_times(dv.converted - (ft_hexlen(&dv.hex)), ' ');
                return (0);
            }
            else
            {
                print_x_times(dv.converted - (ft_hexlen(&dv.hex)), ' ');
                ft_put_address(dir, &dv.hex);
                return (0);
            }
            return (0);
        }
        return (0);
    }
    if (dv.temp[1] == '-' && dv.temp[2] == '*')
    {
        dv.converted = va_arg(args2, int);
        dv.hex = *(va_arg(args2, long *));
        if (dv.converted < 0)
            dv.converted *= -1;
        ft_put_address(dir, &dv.hex);
        print_x_times(dv.converted - (ft_hexlen(&dv.hex)), ' ');
        return (0);
    }
    dv.hex = *(va_arg(args2, long *));
    dv.converted = ft_atoi(&dv.temp[1]);
    if (dv.temp[1] == '-' && ft_isdigit(dv.temp[2]))
    {
        if (dv.converted < 0)
            dv.converted *= -1;
        ft_put_address(dir, &dv.hex);
        print_x_times(dv.converted - (ft_hexlen(&dv.hex)), ' ');
        return (0);
    }
    if (ft_isdigit(dv.temp[1]))
    {
        if (dv.converted < 0)
        {
            dv.converted *= -1;
            print_x_times(dv.converted - (ft_hexlen(&dv.hex)), ' ');
            ft_put_address(dir, &dv.hex);
            return (0);
        }
        print_x_times(dv.converted - (ft_hexlen(&dv.hex)), ' ');
        ft_put_address(dir, &dv.hex);
        return (0);
    }
    return (0);
} */
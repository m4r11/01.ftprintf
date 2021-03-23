/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:01:19 by user              #+#    #+#             */
/*   Updated: 2021/03/23 22:49:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char precision_s(char *dir, va_list args2)
{
    int start;
    int real;
    int x;
    char *print;

    print = va_arg(args2, char *);
    //debug_str(print, "print");
    start = ft_intstrchr(dir, '%', 0);
    real = (ft_intstrchr(dir, '%', start) + 2);
    ft_putc(dir[real]);
    x = ft_atoi(&dir[real]);
    ft_putstr_limit(print, x);
    ft_putstr_limit(print, x);
    //debug_number(real, "real");
    return (0);
}

char precision_int(char *dir, va_list args2)
{
    int start;
    static int real;
    int x;
    int print;
    int width;
    static int position;
    int arglen = ft_arglen(dir);

    position += 1;
    print = va_arg(args2, int);
    start = ft_intstrchr_flag(dir, '%', position);
    real = (ft_intstrchr(dir, '.', start));
    width = find_width(dir, start);
    x = ft_atoi(&dir[real + 1]);
    int len = ft_intlen(print);
    debug_number(len, "len");
    debug_number(x, "x");
    debug_number(width, "w");
/*     debug_number(real, "real");
    debug_number(print, "print"); */
    if (real == -1 && width == 0)
        return (0);
    if (print < -100000000 || print > 100000000)
        return(0);
    if ((x == 0 && ft_isalpha(dir[real])) || real == -1)
        return (0);
    if (len < x)
    {
        if (width >= 0 && print >= 0)
        {
       
                print_x_times(width - x, ' ');
                print_x_times(x - len, '0');
                ft_putnbr(print);
        } 
        if (width >= 0 && print < 0)
        {
                print_x_times(width - (x + 1), ' ');
                ft_putc('-');
                print_x_times(x - len, '0');
                ft_putnbr(print * -1);
        }
        else
        {
            printf("im here");
            width *= -1;
            print_x_times(x - len, '0');
            ft_putnbr(print);
            print_x_times(width - x, ' ');
        }
       return(0);
    }
    if (len > x)
    {
        if (width >= 0 && print >= 0)
        {
    
                print_x_times(width - x, ' ');
                print_x_times(x - len, '0');
                ft_putnbr(print);
        }
        if (width >= 0 && print < 0)
        {
                ft_putc('-');
                print_x_times(width - x, ' ');
                print_x_times(x - len, '0');
                ft_putnbr(print * -1);
        }
        else
        {
            printf("😈");
            width *= -1;
            print_x_times(x - len, '0');
            ft_putnbr(print);
            print_x_times(width - x, ' ');
        }
        return (0);
    }
    position += real;
    return (0);
}

char put_dec_precision(char *dir, va_list args2, int flag)
{
    if (flag == 8)
        return (precision_s(dir, args2));
    if (flag == 0)
    {
        printf("your cute program returned this func 👽");
        return (precision_int(dir, args2));
    }
    if (flag == 13)
    {
        printf("your cute program returned this func 👽");
        return (precision_int(dir, args2));
    }
    //ft_putstr("precision");
    return (0);
}
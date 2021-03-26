/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:01:19 by user              #+#    #+#             */
/*   Updated: 2021/03/26 18:33:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char precision_s(char *dir, va_list args2)
{
    int start;
    int real;
    int min_c;
    int width;
    int new;
    static int pin;
    char  *print;

    print = va_arg(args2, char *);
    start = ft_intstrchr_flag(dir, '%', pin);
    if (dir[start + 1] == '*')
        start = ft_intstrchr_flag(dir, '%', 3);
    real = ft_intstrchr(dir, '.', start) + 1;
    width = ft_atoi(&dir[start + 1]);
    min_c = ft_atoi(&dir[real]);
    if (print == NULL)
    {
        if (width)
        {
            if (width < 0)
            {
                width *= -1;
                print_x_times(width, ' ');
                return (0);
            }
            else
            {
                print_x_times(width, ' ');
                return (0);
            }
        }
        else
        {
            ft_putstr(NULL);
            return (0);
        }

        /*   debug_number(width, "w");
        debug_number(min_c, "minc"); */
        return (0);
    }
    if (dir[real - 2] == '*')
    {
        new = ft_intstrchr(dir, '*', start) + 1;
        real = ft_intstrchr(dir, '%', new) + 1;
        min_c = ft_atoi(&dir[real + 1]);
        ft_putstr_limit(print, min_c);
        return (0);
    }
    pin += 1;
    if (print == NULL)
        exit (0);
    if (ft_strlen(print) == min_c)
    {
        //printf("cute");
        if (width > (ft_strlen(print)))
            print_x_times(width - (ft_strlen(print)), ' ');
        ft_putstr(print);
        if (width < 0)
        {
            width *= -1;
            print_x_times(width - (ft_strlen(print)), ' ');
        }
        return (0);
    }
    if (ft_strlen(print) < min_c)
    {
        if (width > (ft_strlen(print)))
            print_x_times(width - (ft_strlen(print)), ' ');
        ft_putstr(print);
        if (width < 0)
        {
            width *= -1;
            print_x_times(width, ' ');
        }
        return (0);
    }
    else
    {
        if (width < 0)
        {
            ft_putstr_limit(print, min_c);
            width *= -1;
            print_x_times(width - (min_c), ' ');
            return (0);
        }
        else
        {
            print_x_times(width - (min_c), ' ');
            ft_putstr_limit(print, min_c);
            return (0);
        }
    }
    //todo: s combos :)
    return (0);
}

char precision_int_combos(char *dir, va_list args2)
{
    /* this func handles the combination of field '-' star '*' precision '.' */
    int width = va_arg(args2, int);
    int min_c = va_arg(args2, int);
    int print = va_arg(args2, int);
    int len = ft_intlen(print);
    /*    debug_number(width, "width");
    debug_number(min_c, "minc");
    debug_number(print, "print");
    debug_number(len, "len"); */
    //debug_str(dir, "dir");

    //printf("cute program alert\n");
    precision_op(len, min_c, width, print);
    return (0);
}

char precision_int(char *dir, va_list args2)
{
    static int position;
    static int real;
    int min_c;
    int print;
    int width;
    int start;

    start = ft_intstrchr_flag(dir, '%', position);
    //debug_number(start, "***START***");
    if (dir[start + 1] == '-' && dir[start + 2] == '*' && dir[start + 3] == '.')
        return (precision_int_combos(&dir[start], args2));

    real = (ft_intstrchr(dir, '.', start));
    width = find_width(dir, start);
    min_c = ft_atoi(&dir[real + 1]);
    /*     debug_number(width, "w");
    debug_number(real, "r");
    debug_number(min_c, "min"); */
    if (min_c == 0)
        return (0);
    position += 1;
    print = va_arg(args2, int);
    int len = ft_intlen(print);
    if (real == -1 && width == 0)
        return (0);
    if (print < -100000000 || print > 100000000)
        return (0);
    if ((min_c == 0 && ft_isalpha(dir[real])) || real == -1)
        return (0);
    precision_op(len, min_c, width, print);
    position += real;
    return (0);
}

char put_dec_precision(char *dir, va_list args2, int flag)
{
    if (flag == 8)
    {
        return (precision_s(dir, args2));
    }
    if (flag == 0 || flag == 13)
        return (precision_int(dir, args2));
    return (0);
}
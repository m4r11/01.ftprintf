/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:01:19 by user              #+#    #+#             */
/*   Updated: 2021/03/28 16:48:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char precision_s(char *dir, va_list args2)
{
    static int pin;
    t_dir_variables dv;

    dv.print = (va_arg(args2, char *));
    dv.start = ft_intstrchr_flag(dir, '%', pin);
    if (dir[dv.start + 1] == '*')
        dv.start = ft_intstrchr_flag(dir, '%', 3);
    dv.real = ft_intstrchr(dir, '.', dv.start) + 1;
    dv.width = ft_atoi(&dir[dv.start + 1]);
    dv.min_c = ft_atoi(&dir[dv.real]);
    if (dv.print == NULL)
        return(ft_print_null(dv.print, dv.width, dv.min_c));
    if (dir[dv.real - 2] == '*')
        return(ft_wrong_directive(dir, dv.print, dv.width, dv.min_c));
    pin += 1;
    if (ft_strlen(dv.print) == dv.min_c)
        return(ft_micro_same_len(dv.print, dv.width, dv.min_c));
    if (ft_strlen(dv.print) < dv.min_c)
        return(ft_micro_less_len(dv.print, dv.width, dv.min_c));
    else
        return(ft_micro_less_width(dv.print, dv.width, dv.min_c));
    return (0);
}

char precision_int_combos(char *dir, va_list args2)
{
    /* this func handles the combination of field '-' star '*' precision '.' */
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%'));
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);

    int width = va_arg(args2, int);
    int min_c = va_arg(args2, int);
    int print = va_arg(args2, int);
    int len = ft_intlen(print);
    //debug_str(dv.temp, "temp");
    if(dv.temp[1] == '-' && width > 0)
        width *= -1;
/*     debug_number(width, "w");
    debug_number(min_c, "m");
    debug_number(print, "p");
    debug_number(len, "len"); */
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
    if (dir[start + 1] == '-' && dir[start + 2] == '*' && dir[start + 3] == '.')
        return (precision_int_combos(&dir[start], args2));

    real = (ft_intstrchr(dir, '.', start));
    width = find_width(dir, start);
    min_c = ft_atoi(&dir[real + 1]);
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

    if (flag == 8 && dir[ft_intstrchr(dir, '.', 0) + 1] == '*')
        return(star_s(dir, args2));
    if (flag == 8)
        return (precision_s(dir, args2));
    if (flag == 0 || flag == 13)
        return (precision_int(dir, args2));
    return (0);
}
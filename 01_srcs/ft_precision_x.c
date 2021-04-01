/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:01:00 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/01 19:36:22 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char precision_op_x(int len, int min_c, int width, long print)
{
    if (min_c == 0)
        return(zero_min_c_x(len, min_c, width, print));

    if (len < min_c)
        return (minor_len_x(len, min_c, width, print));
/* til now use above */   
    if (len >= min_c)
        return (greater_len_x(len, min_c, width, print));
    return(0);
}

char precision_x_combos(char *dir, va_list args2, int flag)
{
    /* this func handles the combination of field '-' star '*' precision '.' */
    static int pin;
    char to_convert[500];
    t_dir_variables dv;
    //ft_printf("here");
   //debug_number(dv.passflag, "flag");
    dv.temp = (ft_strchr(&dir[pin], '%'));
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);

    int width = va_arg(args2, int);
    int min_c = va_arg(args2, int);
    long print = va_arg(args2, long);
    int len = ft_hexlen(&print);
    //debug_str(dv.temp, "temp");
    if (dv.temp[1] == '-' && width > 0)
        width *= -1;
    /*     debug_number(width, "w");
    debug_number(min_c, "m");
    debug_number(print, "p");
    debug_number(len, "len"); */
    //debug_number(len, "len");
    precision_op_x(len, min_c, width, print);
    return (0);
}

char precision_x(char *dir, va_list args2)
{
    static int position;
    static int real;
    int min_c;
    long print;
    int width;
    int start;
    t_dir_variables dv;

    start = ft_intstrchr_flag(dir, '%', position);
    if (dir[start + 1] == '-' && dir[start + 2] == '*' && dir[start + 3] == '.')
        return (precision_x_combos(&dir[start], args2, dv.passflag));
    real = (ft_intstrchr(dir, '.', start));
    width = find_width(dir, start);
    min_c = ft_atoi(&dir[real + 1]);
    position += 1;
    print = va_arg(args2, long);
    int len = ft_xlen(print);

    if (real == -1 && width == 0)
        return (0);
    if ((min_c == 0 && ft_isalpha(dir[real])) || real == -1)
        return (0);
    if (width == 0 && min_c == 0 && print != 0)
        ft_put_x(print);
    if (print == 0 && min_c == 0)
    {
        print_x_times(width, ' ');
        return (0);
    }
    precision_op_x(len, min_c, width, print);
    position += real;
    return (0);
}
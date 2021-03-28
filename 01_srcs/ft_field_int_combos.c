/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_int_combos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:49:55 by user              #+#    #+#             */
/*   Updated: 2021/03/28 21:08:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_int_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    //debug_str(dv.temp, "temp");
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
    {
        if (dv.temp[2] == '*' && dv.temp[3] == '.' && dv.temp[4] == '*')
        {
            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, int);
            if (dv.min_c > dv.width)
            {
                print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            }
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.temp[2] == '*' && (dv.temp[3] == 'd' || dv.temp[3] == 'i')) /* || dv.temp[3] == 'i' || dv.temp[3] == 'u') */
        {
            dv.width = va_arg(args2, int);
            dv.x = va_arg(args2, int);
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        return (0);
    }
    if(dv.temp[0] == '-' && dv.temp[1] == '0' && dv.temp[2] == '*')
    {
        dv.width = va_arg(args2, int);
        dv.min_c = ft_atoi(&to_convert[4]);
        dv.x = va_arg(args2, int);
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        ft_putnbr(dv.x);
        if(dv.min_c == 0)
        {
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return(0);
        }
        print_x_times(dv.width - dv.min_c, ' ');
 /*        debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        debug_number(dv.x, "x"); */
    }
    return (0);
}

/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "min_c");
        debug_number(dv.x, "x"); */

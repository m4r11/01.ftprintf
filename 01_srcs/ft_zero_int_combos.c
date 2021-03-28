/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_int_combos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:38:22 by user              #+#    #+#             */
/*   Updated: 2021/03/28 21:34:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char zero_int_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    //ft_printf("hello2");
    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    if (dv.temp[1] == '-')
        dv.temp = (ft_strchr(dv.temp, '%') + 1);
    //debug_str(dv.temp, "temp");
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == '.' && dv.temp[3] == '*')
    {
        dv.width = va_arg(args2, int);
        dv.min_c = va_arg(args2, int);
        dv.x = va_arg(args2, int);
        if (dv.width > dv.min_c && dv.x < 0)
            print_x_times(dv.width - dv.min_c - 1, ' ');
        if (dv.x < 0)
        {
            dv.x *= -1;
            ft_putc('-');
        }
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && (dv.temp[2] == 'd' || dv.temp[2] == 'i'))
    {
        dv.width = va_arg(args2, int);
        dv.x = va_arg(args2, int);
        if (dv.x < 0)
        {
            dv.x *= -1;
            ft_putc('-');
        }
        print_x_times(dv.width - ft_intlen(dv.x) - 1, '0');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.temp[2] == '.' && ft_isdigit(dv.temp[3]))
    {
        dv.width = va_arg(args2, int);
        dv.min_c = ft_atoi(&to_convert[3]);
/*         debug_number(dv.min_c, "min");
        debug_number(dv.width, "w"); */
        dv.x = va_arg(args2, int);
        if (dv.min_c == 0)
        {
            if (dv.width < 0)
            {
                dv.width *= -1;
                ft_putnbr(dv.x);
                print_x_times(dv.width - ft_intlen(dv.x), ' ');
                return(0);
            }
            print_x_times(dv.width, ' ');
            return (0);
        }
        if(dv.x < 0)
        {
            print_x_times(dv.width - dv.min_c - 1, ' ');
             ft_putnbr(dv.x);
            print_x_times(ft_intlen(dv.x) - dv.width, '0');
            return (0);       
        }
        print_x_times(dv.width - dv.min_c, ' ');
        ft_putnbr(dv.x);
        print_x_times(ft_intlen(dv.x) - dv.width, '0');
        return (0);
    }
    //ft_printf("cute zeros");
    return (0);
}

/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "min_c");
        debug_number(dv.x, "x"); */
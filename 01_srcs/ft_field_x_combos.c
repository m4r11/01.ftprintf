/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_x_combos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:56:02 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/02 19:29:49 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_x_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    /* *%-*.*x* */
    if (dv.temp[0] == '-' && dv.temp[1] == '*')
    {
        /* TESTE9 prim parte */
        dv.width = va_arg(args2, int);
        dv.min_c = va_arg(args2, int);
        dv.x = va_arg(args2, long);
        /*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        printf("debug x: %x", dv.x); */
        print_x_times(dv.min_c - ft_xlen(dv.x), '0');
        ft_put_x(dv.x);
        print_x_times(dv.width - ft_xlen(dv.x), ' ');
        return (0);
    }
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
    {
        if (dv.temp[2] == '*' && dv.temp[3] == '.' && dv.temp[4] == '*')
        {

            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, long);
            if (dv.min_c > dv.width)
            {
                print_x_times(dv.min_c - ft_xlen(dv.x), '0');
            }
            ft_put_x(dv.x);
            print_x_times(dv.width - ft_xlen(dv.x), ' ');
            return (0);
        }
        if (dv.temp[2] == '*' && (dv.temp[3] == 'x' || dv.temp[3] == 'x')) /* || dv.temp[3] == 'i' || dv.temp[3] == 'u') */
        {
            dv.width = va_arg(args2, int);
            dv.x = va_arg(args2, long);
            ft_put_x(dv.x);
            print_x_times(dv.width - ft_xlen(dv.x), ' ');
            return (0);
        }
        return (0);
    }
    if (dv.temp[0] == '-' && dv.temp[1] == '0' && dv.temp[2] == '*')
    {

        dv.width = va_arg(args2, int);
        dv.min_c = ft_atoi(&to_convert[4]);
        dv.x = va_arg(args2,  long);
        if (dv.width < 0)
            dv.width *= -1;
            if (dv.min_c < ft_intlen(dv.x))
            {
                ft_put_x(dv.x);
                print_x_times(ft_xlen(dv.x) - dv.width, '0');
                print_x_times(dv.width - ft_xlen(dv.x) + 1, ' ');
                return (0);
            }
            print_x_times(dv.min_c - ft_xlen(dv.x), '0');
            ft_put_x(dv.x);
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
 
        /*       debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        debug_number(dv.x, "x"); */
    }
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == '.')
    {
        if (dv.temp[3] == '*')
        {
            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, long);
            /*      debug_number(dv.width, "w");
            debug_number(dv.min_c, "m"); */
            print_x_times(dv.width - dv.min_c, ' ');
            print_x_times(dv.min_c - ft_xlen(dv.x), '0');
            ft_put_x(dv.x);
            return (0);
        }
        else
        {
            dv.width = va_arg(args2, int);
            dv.min_c = ft_atoi(&to_convert[3]);
            dv.x = va_arg(args2, long);
/*             debug_number(dv.width, "w");
            debug_number(dv.min_c, "m");
            debug_number(dv.x, "x"); */
            if(dv.width < 0)
            {
                 dv.width *= -1;
                 ft_put_x(dv.x);
                 print_x_times(dv.width - ft_xlen(dv.x), ' ');
                 print_x_times(dv.min_c - ft_intlen(dv.x), '0');
                    return(0);

            }
            if ( dv.x == 0)
            {
                print_x_times(dv.width - dv.min_c, ' ');
                print_x_times(dv.min_c - ft_intlen(dv.x), '0');
                return(0);
            }
            print_x_times(dv.width - dv.min_c, ' ');
            print_x_times(ft_xlen(dv.x) - dv.min_c  -1, '0');
            ft_put_x(dv.x);
            return (0);
        }
    }
    return (0);
}

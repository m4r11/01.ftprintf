/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_u_combos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:28:14 by user              #+#    #+#             */
/*   Updated: 2021/03/30 19:47:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_u_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    //printf("***CUTE PROGRAM ALERT***\n");
    /* impassingheretwice */
    dv.start = ft_intstrchr_flag(dir, '%', pin) + 1;
    dv.real = (ft_intstrchr(dir, '.', dv.start));
    pin = ft_intstrchr(dir, '%', pin);
    /*     dv.x = va_arg(args2, int);
    int len = ft_intlen(dv.x); */
    debug_str(&dir[dv.start], "dir");
    if (dir[dv.start] == '-')
    {
        dv.width = find_width(dir, dv.start);
        dv.min_c = ft_atoi(&dir[dv.real + 1]);
        dv.x = va_arg(args2, unsigned int);
        dv.len = ft_intlen(dv.x);
/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        printf("%u\n", dv.x);
        debug_number(dv.len, "len"); */
        if (dv.min_c > dv.len)
        {
            print_x_times(dv.min_c - dv.len, '0');
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        if (dv.min_c == dv.len)
        {
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
    }
    if(dir[dv.start] == '0')
    {
        //printf("here");
        if(dir[dv.start + 1] == '-' && dir[dv.start + 2] == '*' && dir[dv.start + 3] == '.' && dir[dv.start + 4] == '*')
        {
            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, unsigned int);
  /*           debug_number(dv.width, "w");
            debug_number(dv.min_c, "m");
            debug_number(dv.x, "x"); */

            if (dv.width > dv.min_c && dv.min_c < ft_u_intlen(dv.x))
            {
                ft_putnbr_u(dv.x);
                print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
                return(0);
            }
            if (dv.width < dv.min_c && dv.min_c > ft_u_intlen(dv.x))
            {
                print_x_times(dv.min_c - dv.width, '0');
                ft_putnbr_u(dv.x);
                return(0);
            }
        }
        if(dir[dv.start + 1] == '*' && dir[dv.start + 2] == '.' && dir[dv.start + 3] == '*' )
        {
            ft_printf("here");
            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, unsigned int);
            debug_number(dv.width, "w");
            debug_number(dv.min_c, "m");
            printf(" u : %u", dv.x);
            if (dv.width > dv.min_c && dv.min_c < ft_u_intlen(dv.x))
            {
                ft_putnbr_u(dv.x);
                print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
                return(0);
            }
            if (dv.width > dv.min_c )
            {
                if (dv.x < 0)
                    dv.x *= -1; 
                print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
                ft_putnbr_u(dv.x);
                return(0);
            }
            if (dv.width < dv.min_c && dv.min_c > ft_u_intlen(dv.x))
            {
                print_x_times(dv.min_c - dv.width, '0');
                ft_putnbr_u(dv.x);
                return(0);
            }
        }
        return(0);
    }
    if (ft_isdigit(dir[dv.start]))
    {
       //printf("here");
        dv.width = ft_atoi(&dir[dv.start]);
        dv.min_c = ft_atoi(&dir[dv.real + 1]);
        dv.x = va_arg(args2, unsigned int);
        //printf("this us %u <-here", dv.x);
/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        printf("%u\n", dv.x);
        debug_number(dv.len, "len"); */
        if (dv.min_c > dv.width && dv.x == 0)
        {
            print_x_times(dv.min_c, '0');
            //ft_putnbr_u(dv.x);
            return (0);
        }
        if (dv.min_c > dv.width && dv.x < 0)
        {
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            return (0);
        }
        return (0);
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_4_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:52:31 by user              #+#    #+#             */
/*   Updated: 2021/03/28 16:24:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char position_address(char *dir, va_list args2)
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
        dv.hex = va_arg(args2, long *);
        {
            if (dv.converted < 0)
            {
                dv.converted *= -1;
                ft_put_address(dir, dv.hex);
                print_x_times(dv.converted - (ft_hexlen(dv.hex)), ' ');
                return (0);
            }
            else
            {
                print_x_times(dv.converted - (ft_hexlen(dv.hex)), ' ');
                ft_put_address(dir, dv.hex);
                return (0);
            }
            return (0);
        }
        return (0);
    }
    if (dv.temp[1] == '-' && dv.temp[2] == '*')
    {
        dv.converted = va_arg(args2, int);
        dv.hex = va_arg(args2, long *);
        if (dv.converted < 0)
            dv.converted *= -1;
        ft_put_address(dir, dv.hex);
        print_x_times(dv.converted - (ft_hexlen(dv.hex)), ' ');
        return (0);
    }
    dv.hex = va_arg(args2, long *);
    dv.converted = ft_atoi(&dv.temp[1]);
    if (dv.temp[1] == '-' && ft_isdigit(dv.temp[2]))
    {
        if (dv.converted < 0)
            dv.converted *= -1;
        ft_put_address(dir, dv.hex);
        print_x_times(dv.converted - (ft_hexlen(dv.hex)), ' ');
        return (0);
    }
    if (ft_isdigit(dv.temp[1]))
    {
        if (dv.converted < 0)
        {
            dv.converted *= -1;
            print_x_times(dv.converted - (ft_hexlen(dv.hex)), ' ');
            ft_put_address(dir, dv.hex);
            return (0);
        }
        print_x_times(dv.converted - (ft_hexlen(dv.hex)), ' ');
        ft_put_address(dir, dv.hex);
        return (0);
    }
    return (0);
}
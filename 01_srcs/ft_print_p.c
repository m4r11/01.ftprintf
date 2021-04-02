/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:00:12 by user              #+#    #+#             */
/*   Updated: 2021/04/02 15:52:06 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_ptr(char *input, int has_format, va_list args2)
{
    long *print;

    if (has_format == -1)
    {
        print = va_arg(args2, long *);
        ft_put_address(input, print);
    }  
    return;
}

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
}
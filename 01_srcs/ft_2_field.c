/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:59:38 by user              #+#    #+#             */
/*   Updated: 2021/03/27 14:48:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** dv. stands for "directives variables" stored in opaque typedef t_dir_variables in printf.h
*/

char field_s(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;
    
    dv.temp = (ft_strchr(&dir[pin], '%'));
    dv.verify = ft_strchr(dir, '.');
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    if(dv.verify && (ft_isdigit(dv.verify[1]) || dv.verify[1] == '-'))
        return(precision_s(dir, args2));
    dv.converted = ft_simple_atoi(&to_convert[pin + 1]);
    pin = ft_intstrchr(dir, '%', pin);
    dv.x1 = va_arg(args2, char *);
    if (dv.x1 == NULL)
        return(precision_s(dir, args2));
    dv.x1converted = ft_simple_atoi(dv.x1);
    dv.x1len = ft_intlen(dv.x1converted);
    if(dv.verify && dv.verify[1] == 's')
        return(print_x_times(dv.converted, ' '));
    if (dv.temp[1] == '-')
        return(put_spaces_afer_s(dv.x1, dv.converted, dv.x1len));
    else
        return(put_spaces_before_s(dv.x1, dv.converted, dv.x1len));
    return (0);
}

char field_c_combos(char *dir, va_list args2)
{

    int x;
    char to_convert[500];
    int converted;
    char *temp;
    
    temp = (ft_strchr(dir, '%') + 1);
    if (temp[0] == '-' && temp[1] == '*')
    {
        x = va_arg(args2, int);
        converted = va_arg(args2, int);
        if (x >= 0)
        {
            ft_putc(converted);
            print_x_times(x - 1, ' ');
            return (0);
        }
        if (x < 0)
        {
            x *= -1;
            ft_putc(converted);
            print_x_times(x - 1, ' ');
            return (0);
        }
    }
    return (0);
}

char put_field(char *dir, va_list args2, int flag)
{

    char to_convert[500];
    t_dir_variables dv;
    
    dv.temp = (ft_strchr(dir, '%') + 1);
    dv.len = ft_strlen(dv.temp);
    if (flag == 8)
        return (field_s(dir, args2));
    if (((dv.temp[0] == '-' || ft_isdigit(dv.temp[0]) == 1) && dv.temp[1] == '.') ||
        dv.temp[2] == '.' || dv.temp[3] == '.')
        return (precision_int(dir, args2));
    if (dv.temp[0] == '-' && dv.temp[1] == '*')
        return (field_c_combos(dir, args2));
    ft_copy(dv.temp, to_convert);
    dv.converted = ft_simple_atoi(to_convert);
    dv.x = va_arg(args2, int);
    if (dv.temp[0] == '-')
        return(put_spaces_afer_c(dv.x, dv.converted));
    else
        return(put_spaces_before_c(dv.x, dv.converted));
    return (0);
}

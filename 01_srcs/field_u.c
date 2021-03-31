/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:50:19 by user              #+#    #+#             */
/*   Updated: 2021/03/31 20:10:49 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_u(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    pin = ft_intstrchr(dir, '%', pin);

    /*   debug_str(dv.temp, "temp"); */
    /* ->| %0- |<-  */
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
        return (zero_u_combos(dir, args2));
        /* ->| %0* |<-  */
    if (dv.temp[0] == '0' && dv.temp[1] == '*')
        return (zero_u_combos(dir, args2));
    /* ->| %-0 |<-  */
    if (dv.temp[0] == '-' && dv.temp[1] == '0')
        return (field_u_combos(dir, args2));
    /* ->| %0. |<-  */
    if (dv.temp[0] == '0' && dv.temp[2] == '.')
        return (zero_u_combos(dir, args2));
    /* ->| %01 |<-  */
    if (dv.temp[0] == '0' && ft_isdigit(dv.temp[1]))
        return (zero_u_combos(dir, args2));
    /* ->| %-* |<-  */
    if (dv.temp[0] == '-' && dv.temp[1] == '*')
        return (field_u_combos(dir, args2));
    /* ->| %-1. || % 10. |<-  */
    if (((dv.temp[0] == '-' || ft_isdigit(dv.temp[0]) == 1) && dv.temp[1] == '.') ||
        dv.temp[2] == '.' || dv.temp[3] == '.')
        return (precision_u(dir, args2));

        
    /* ->| else |<-  */
    ft_copy(dv.temp, to_convert);
    dv.converted = ft_simple_atoi(to_convert);
    dv.x = va_arg(args2, unsigned int);
    if (dv.temp[0] == '-')
        return (put_spaces_afer_u(dv.x, dv.converted));
    else
        return (put_spaces_before_u(dv.x, dv.converted));
    return (0);
}

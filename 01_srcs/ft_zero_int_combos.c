/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_int_combos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:38:22 by user              #+#    #+#             */
/*   Updated: 2021/04/01 18:59:34 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char zero_int_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    if (dv.temp[1] == '-')
        dv.temp = (ft_strchr(dv.temp, '%') + 1);
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == '.' && dv.temp[3] == '*')
        return (zero_star_dot_star(args2));
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == '.' && ft_isdigit(dv.temp[3]))
        return (zero_star_dot_digi(args2, to_convert));
    /* ->| %0*d |<- */
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && (dv.temp[2] == 'd' || dv.temp[2] == 'i'))
        return (zero_star_flag(args2));
    /* ->| %010.4d |<- */
    if (ft_isdigit(dv.temp[1]) && ft_isdigit(dv.temp[2]) && dv.temp[3] == '.' && ft_isdigit(dv.temp[4]))
        return(zero_2digi_dot_flag(args2, to_convert));
    /* ->| %01.4d |<- */
    if (dv.temp[2] == '.' && ft_isdigit(dv.temp[3]))
        return(zero_1digit_dot_flag(args2, to_convert));
return (0);
}


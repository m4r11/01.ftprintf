/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:50:19 by user              #+#    #+#             */
/*   Updated: 2021/03/30 19:37:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h" 

char    field_u(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    pin = ft_intstrchr(dir, '%', pin);

    ft_copy(dv.temp, to_convert);
    dv.converted = ft_simple_atoi(to_convert);
    //debug_str(dv.temp, "temp");
    if(dv.temp[0] == '0')
        return(field_u_combos(dir, args2));
    if(dv.temp[0] == '*' || dv.temp[1] == '*' || dv.temp[1] == '.' || dv.temp[2] == '.')
        return(field_u_combos(dir, args2));
    dv.x = va_arg(args2, unsigned int);
    if (dv.temp[0] == '-')
        return(put_spaces_afer_u(dv.x, dv.converted));
    else
        return(put_spaces_before_u(dv.x, dv.converted));
    return (0);
}

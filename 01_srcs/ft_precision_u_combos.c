/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_u_combos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:42:46 by user              #+#    #+#             */
/*   Updated: 2021/03/31 16:04:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* handles " *%-*.*u* *%-*.*u* " */
char precision_u_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;
   //printf("imhere");

    dv.temp = (ft_strchr(&dir[pin], '%')) + 1;
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    dv.width = va_arg(args2, int);
    dv.min_c = va_arg(args2, int);
    dv.x = va_arg(args2, unsigned int);
    dv.len = ft_u_intlen(dv.x);

/*     debug_str(&dv.temp[pin], "tep"); */
     //if (dv.temp[pin] == '-' && dv.width > 0)
    
/*     debug_number(dv.width, "w");
    debug_number(dv.min_c, "m");
    printf("%u\n", dv.x);
    debug_number(dv.len, "len"); */
    if(dv.min_c > dv.width && dv.width > 0)
    {
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        return(0);
    }
    if(dv.min_c < (dv.width * -1) && dv.width < 0)
    {
        dv. width *= -1;
        ft_putnbr_u(dv.x);
        print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
        return(0);
    }

    return(0);
}

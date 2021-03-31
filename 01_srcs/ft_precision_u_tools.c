/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_u_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:24:07 by user              #+#    #+#             */
/*   Updated: 2021/03/31 20:01:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char minor_len_u(int len, int min_c, int width, int print)
{
    if (width >= 0 && print >= 0)
    { 
        ft_micro_great_width_great_len_u(width, min_c, len);
        ft_putnbr_u(print);
        return (0);
    }
    if (width >= 0 && print < 0)
        return(ft_micro_great_width_less_print_u(width, min_c, print, len));
    if (width < 0 && print < 0)
    {
        width *= -1;
        return(ft_micro_great_width_less_print_u(width, min_c, print, len));
    }
    if (width < 0 && print >= 0)
    {
        width *= -1;
        print_x_times(min_c - len, '0');
        ft_putnbr_u(print);
        print_x_times(width - min_c, ' ');
        return (0);
    }
    return (0);
}

char greater_len_u(int len, int min_c, int width, int print)
{
/*     ft_printf("ola");
    debug_number(width, "w");
    debug_number(min_c, "m"); */
    if (width >= 0 && print >= 0)
    {
        ft_micro_great_width_great_len_u(width, min_c, len);
        ft_putnbr_u(print);
        return(0);
    }
    if (width >= 0 && print < 0 && len > width)
    {
        ft_micro_great_width_great_len_u(width, min_c, len);
        ft_putnbr_u(print);
        return(0);
    }
    if(width < 0 && min_c < len)
    {
        width *= -1;
        ft_putnbr_u(print);
        print_x_times(width - len, ' ');
        return(0);
    }
    if(width < 0 && min_c == len && print < 0)
    {
        width *= -1;
        print_x_times(min_c - ft_u_intlen(print), '0');
        ft_putnbr_u(print);
        print_x_times(width - len, ' ');
        return(0);
    }
    if (width >= 0 && print < 0 && width > min_c)
     {
        print_x_times(width - ft_u_intlen(print), ' ');
          print_x_times(min_c - ft_u_intlen(print), '0');
          ft_putnbr_u(print);
          return(0);
     }
    else    
    {
        width *= -1;
        print_x_times(min_c - len, '0');
        ft_putnbr_u(print);
        print_x_times(width - min_c, ' ');
    }
    return (0);
}

char zero_min_c_u(int len, int min_c, int width, int print)
{
    if (width > 0)
    {
       print_x_times(width - ft_u_intlen(print), ' ');
        ft_putnbr_u(print);
    }
    if (width < 0)
    {
        ft_putnbr_u(print);
        width *= -1;
        print_x_times(width - ft_u_intlen(print), ' ');
    }
    return(0);
}

char precision_op_u(int len, int min_c, int width, int print)
{
    if (min_c == 0)
        return(zero_min_c_u(len, min_c, width, print));
    if (len < min_c)
        return (minor_len_u(len, min_c, width, print));
    if (len >= min_c)
        return (greater_len_u(len, min_c, width, print));
    return(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:49:51 by user              #+#    #+#             */
/*   Updated: 2021/04/01 16:41:50 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char minor_len(int len, int min_c, int width, int print)
{
    if (width >= 0 && print >= 0)
    { 
        ft_micro_great_width_great_len(width, min_c, len);
        ft_putnbr(print);
        return (0);
    }
    if (width >= 0 && print < 0)
        return(ft_micro_great_width_less_print(width, min_c, print, len));
    if (width < 0 && print < 0)
    {
        width *= -1;
        return(ft_micro_great_width_less_print(width, min_c, print, len));
    }
    if (width < 0 && print >= 0)
    {
        width *= -1;
        print_x_times(min_c - len, '0');
        ft_putnbr(print);
        print_x_times(width - min_c, ' ');
        return (0);
    }
    return (0);
}

char greater_len(int len, int min_c, int width, int print)
{

    if (width >= 0 && print >= 0)
    {
        ft_micro_great_width_great_len(width, min_c, len);
        ft_putnbr(print);
        return(0);
    }
    if (width >= 0 && print < 0 && len > width)
    {
        ft_putc('-');
        ft_micro_great_width_great_len(width, min_c, len);
        ft_putnbr(print * -1);
        return(0);
    }
    if(width < 0 && min_c < len)
    {
        width *= -1;
        ft_putnbr(print);
        print_x_times(width - len, ' ');
        return(0);
    }
    if(width < 0 && min_c == len && print < 0)
    {
        width *= -1;
        ft_putc('-');
        print_x_times(min_c - ft_intlen(print * -1), '0');
        ft_putnbr(print * -1);
        print_x_times(width - len - 1, ' ');
        return(0);
    }
    if (width >= 0 && print < 0 && width > min_c)
     {
         print_x_times(width - min_c - 1, ' ');
          ft_putc('-');
          print_x_times(min_c - ft_intlen(print * -1), '0');
          ft_putnbr(print * -1);
          return(0);
     }
    else    
    {
        width *= -1;
        print_x_times(min_c - len, '0');
        ft_putnbr(print);
        print_x_times(width - min_c, ' ');
    }
    return (0);
}

char zero_min_c(int len, int min_c, int width, int print)
{
    if (width > 0)
    {
        print_x_times(width - ft_intlen(print), ' ');
        ft_putnbr(print);
    }
    if (width < 0)
    {
        ft_putnbr(print);
        width *= -1;
        print_x_times(width - ft_intlen(print), ' ');
    }
    return(0);
}

char precision_op(int len, int min_c, int width, int print)
{
    if (min_c == 0)
        return(zero_min_c(len, min_c, width, print));
    if (len < min_c)
        return (minor_len(len, min_c, width, print));
    if (len >= min_c)
        return (greater_len(len, min_c, width, print));
    return(0);
}
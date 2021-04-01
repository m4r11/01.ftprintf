/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 16:39:49 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/01 19:37:30 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_xlen(long print)
{
    long decimal;
    long quotient;
    long remainder;
    char hexadecimal[20];
    if (print == 0)
        return(3);
    int j = 0;
    quotient = *(long *)&print;
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    return (j);
}

char ft_micro_great_width_less_print_x(int width, int min_c, long print, int len)
{
    print_x_times(width - (min_c + 1), ' ');
    print_x_times(min_c - (len - 1), '0');
    ft_put_x(print);
    return (0);
}

char ft_micro_great_width_great_len_x(int width, int min_c, long print, int len)
{
    /* you touched this: || */
    //ft_printf("here");
   // debug_number(ft_xlen(print), "len");
    print_x_times(width - min_c, ' ');
    print_x_times(min_c - ft_xlen(print), '0');
    return (0);
}

char ft_print_null_x(char *print, int width, int min_c)
{
    if (width < 0)
    {
        ft_putstr_limit("(null)", min_c);
        width *= -1;
        print_x_times(width - (min_c), ' ');
        return (0);
    }
    else
    {
        print_x_times(width - (min_c), ' ');
        ft_putstr_limit("(null)", min_c);
        return (0);
    }
    return (0);
}

char field_x(char *dir, va_list args2, int flag)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    pin = ft_intstrchr(dir, '%', pin);
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
        return (field_x_combos(dir, args2));
    if (dv.temp[0] == '-' && dv.temp[1] == '0')
        return (field_x_combos(dir, args2));
    if (dv.temp[0] == '0' && dv.temp[1] == '*')
        return (zero_int_combos(dir, args2));
    if (dv.temp[0] == '0' && dv.temp[2] == '.')
        return (zero_int_combos(dir, args2));
    if (dv.temp[0] == '0' && ft_isdigit(dv.temp[1]))
        return (zero_int_combos(dir, args2));
    if (((dv.temp[0] == '-' || ft_isdigit(dv.temp[0]) == 1) && dv.temp[1] == '.') ||
        dv.temp[2] == '.' || dv.temp[3] == '.')
        return (precision_x(dir, args2));
    if (dv.temp[0] == '-' && dv.temp[1] == '*')
        return (field_x_combos(dir, args2));
    ft_copy(dv.temp, to_convert);
    dv.converted = ft_simple_atoi(to_convert);
    dv.hex = va_arg(args2, long);
    if (dv.temp[0] == '-')
        return (put_spaces_afer_x(dv.hex, dv.converted));
    else
        return (put_spaces_before_x(dv.hex, dv.converted));
    return (0);
}

char minor_len_x(int len, int min_c, int width, long print)
{
    if (width >= 0)
    { 
        /* pass here | */
        ft_micro_great_width_great_len_x(width, min_c, print, len);
        ft_put_x(print);
        return (0);
    }
    if (width >= 0 && print < 0)
        return(ft_micro_great_width_less_print_x(width, min_c, print, len));
    if (width < 0 && print < 0)
    {
        width *= -1;
        return(ft_micro_great_width_less_print_x(width, min_c, print, len));
    }
    if (width < 0 && print >= 0)
    {
        /* pass here | */
        width *= -1;
        print_x_times(min_c - len, '0');
        ft_put_x(print);
        print_x_times(width - min_c, ' ');
        return (0);
    }

    return (0);
}

char greater_len_x(int len, int min_c, int width, long print)
{
    if (width >= 0 && print >= 0)
    {
        ft_micro_great_width_great_len_x(width, min_c, print, len);
        ft_put_x(print);
        return(0);
    }
    if (width >= 0 && print < 0 && len > width)
    {
        ft_micro_great_width_great_len_x(width, min_c, print, len);
        ft_put_x(print);
        return(0);
    }
    if(width < 0 && min_c < len)
    {
        /* iwas here |*/
        width *= -1;
        ft_put_x(print);
        print_x_times(len - min_c, '0');
        print_x_times(width - min_c, ' ');
        return(0);
    }
    if(width < 0 && min_c == len && print < 0)
    {
        width *= -1;
        print_x_times(min_c - ft_xlen(print * -1), '0');
        ft_put_x(print);
        print_x_times(width - len - 1, ' ');
        return(0);
    }
    if (width >= 0 && print < 0 && width > min_c)
     {
        print_x_times(width - min_c - 1, ' ');
        print_x_times(min_c - ft_xlen(print), '0');
        ft_put_x(print);
          return(0);
     }
    else    
    {
        width *= -1;
        print_x_times(min_c - len, '0');
        ft_put_x(print);
        print_x_times(width - min_c, ' ');
    }
    return (0);
}

char zero_min_c_x(int len, int min_c, int width, long print)
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


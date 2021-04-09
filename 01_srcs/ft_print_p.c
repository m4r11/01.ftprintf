/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:00:12 by user              #+#    #+#             */
/*   Updated: 2021/04/09 18:45:06 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On this file: once a flag is found, is redirected through the array
** of function pointers ->here<- if 'p' flag. 
** @26 treats padding on the left if width is >= 0
** @39 treats padding on the right if width is < 0
** @64 takes control after print_ptr, to pipe down correct formating option
** @79 core drive for 'p' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
** @103 aux print address function.
*/

#include "ft_printf.h"

int pad_left_p(long long print, int to_pad, int min_c, int zero)
{
    if (min_c > to_pad)
        to_pad = min_c;
    if (min_c == 0 && zero == -1)
        return (ft_pad_left_no_zero_p(print, to_pad, min_c));
    if (to_pad > min_c)
        return (ft_pad_left_big_pad_p(print, to_pad, min_c));
    print_x_times(min_c - to_pad, ' ');
    ft_put_address_up(print, min_c);
    return (0);
}

int pad_right_p(long long  print, int to_pad, int min_c)
{
    if (min_c == 0 && print != 0)
    {
        ft_put_address_up(print, min_c);
        print_x_times((to_pad * -1) - ft_hexlen(print), ' ');
        return (0);
    }
    if (min_c == 0 && print == 0)
        return (print_x_times((to_pad * -1), ' '));
    if (min_c > 0 && print == 0)
        return (print_x_times(min_c, '0'));
    if (min_c != -1 && min_c < ft_xlen(print))
    {
        ft_put_address_up(print, min_c);
        print_x_times((to_pad * -1) - ft_xlen(print), ' ');
        return (0);
    }
    if (min_c == -1)
        return (ft_pad_right_nominc_p(print, to_pad, min_c));
    ft_put_address_up(print, min_c);
    print_x_times((to_pad * -1) - min_c, ' ');
    return (0);
}

int format_address(long long print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
        return (pad_left_p(print, to_pad, min_c, zero));
    if (to_pad < 0)
        return (pad_right_p(print, to_pad, min_c));
    if (to_pad == 0 && min_c > 0)
        ft_put_address_up(print, min_c);
    if (to_pad == 0 && min_c < 0)
        ft_put_address_up(print, min_c);
    else
        return (0);
    return (0);
}

int print_ptr(char *input, int index, int has_format, va_list args2)
{
    long q;
    int width;
    int min_c;
    int zero = ft_intstrchr(input, '0', index);

    if (has_format == -1)
    {
        q = va_arg(args2, long long );
        ft_put_address(q);
        return (ft_intstrchr_flag(input, 'p', index));
    }
    else
    {
        width = find_width_p(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        q = va_arg(args2,long long);
        format_address(q, width, min_c, zero);
        return (ft_intstrchr_flag(input, 'p', index));
    }
    return (FAIL);
}

void ft_put_address_up(long long print, int min_c)
{
    long long quotient;
    long long remainder;
    char hexadecimal[100];
    char *longmin;
    int len;
    int j = 0;

    if (print == 0)
    {
        ft_putstr("0x0");
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 3, '0');
        return;
    }
    if (print == 1)
    {
        ft_putstr("0x1");
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 3, '0');
        return;
    }
    if (print == LONG_MIN)
    {
        longmin = "0x8000000000000000";
        print_x_times(min_c - (ft_strlen(longmin)), '0');
        ft_putstr(longmin);
        return;
    }
    if (print == UINT_MAX + 1)
    {
        ft_putc(' ');
        return;
    }
    quotient = print;
    ft_putc('0');
    ft_putc('x');
    while (quotient != 0)
    {
/*         debug_str(hexadecimal, "h");
        debug_number(quotient, "q");
        if (quotient < 0)
        {
            quotient = UINT_MAX - ((print * -1) - 1);
        } */
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    len = ft_is_hex(hexadecimal);
    if (min_c > 0 && print != 0)
    {
        if (ft_intlen(print) == 1)
            print_x_times(min_c - 1, '0');
        else
            print_x_times(min_c - len, '0');
    }
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    return;
}

/* handy & usefull copy paste costume debug:
debug_number(width, "w");
debug_number(min_c, "m");
 */
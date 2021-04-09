/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:38:53 by user              #+#    #+#             */
/*   Updated: 2021/04/09 13:56:19 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On this file: once a flag is found, is redirected through the array
** of function pointers ->here<- if 'u' flag. 
** @25 treats padding on the left if width is >= 0
** @40 treats padding on the right if width is < 0
** @64 takes control after print_ptr, to pipe down correct formating option
** @79 core drive for 'p' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
** @103 aux print address function.
*/

#include "ft_printf.h"

int ft_pad_left_len_u(int print, int to_pad, int min_c, int c)
{
    print_x_times(to_pad, c);
    ft_putnbr_u_up(print, min_c);
    return (0);
}

int ft_pad_right_u(int print, int to_pad, int min_c)
{
    if (min_c == 0 && print != 0)
    {
        ft_putnbr_u_up(print, min_c);
        print_x_times((to_pad * -1) - ft_u_intlen(print), ' ');
        return (0);
    }
    if (min_c == 0 && print == 0)
        return (print_x_times((to_pad * -1), ' '));
    if (min_c > 0 && print == 0)
    {
        to_pad *= -1;
        ft_putnbr_u_up(print, min_c);
        if (min_c < ft_u_intlen(print))
            print_x_times(to_pad - ft_u_intlen(print), ' ');
        else
            return (print_x_times(to_pad - min_c, ' '));
    }
    if (min_c < ft_u_intlen(print))
    {
        ft_putnbr_u_up(print, min_c);
        print_x_times((to_pad * -1) - ft_u_intlen(print), ' ');
        return (0);
    }
    ft_putnbr_u_up(print, min_c);
    print_x_times((to_pad * -1) - min_c, ' ');
    return (0);
}

int ft_pad_left_u(int print, int to_pad, int min_c, int zero)
{
    if (min_c > to_pad)
        to_pad = min_c;
    if (min_c == 0 && zero == 1)
    {
        if (print == 0)
            return (print_x_times(to_pad, ' '));
        else
            return (ft_pad_left_len_u(print, to_pad - ft_u_intlen(print), min_c, ' '));
    }
    if (min_c == 0 && zero == -3)
    {
        if (print == 0)
            return (print_x_times(to_pad, ' '));
        else
            return (ft_pad_left_len_u(print, to_pad - ft_u_intlen(print), min_c, ' '));
    }
    if (min_c == -1 && zero == 1)
        return (ft_pad_left_len_u(print, to_pad - ft_u_intlen(print), min_c, '0'));
    if (to_pad > min_c)
    {
        if (min_c < ft_u_intlen(print))
            return (ft_pad_left_len_u(print, to_pad - ft_u_intlen(print), min_c, ' '));
        else
            return (ft_pad_left_len_u(print, to_pad - min_c, min_c, ' '));
    }
    return (ft_pad_left_len_u(print, to_pad - min_c, min_c, ' '));
}

int format_u(unsigned int print, int to_pad, int min_c, int zero)
{
    if (to_pad > 0)
        return (ft_pad_left_u(print, to_pad, min_c, zero));
    if (to_pad < 0)
        return (ft_pad_right_u(print, to_pad, min_c));
    if (to_pad == 0 && min_c <= 0 && print != 0)
        ft_putnbr_u_up(print, min_c);
    if (to_pad == 0 && min_c < 0 && print == 0)
        ft_putnbr_u_up(print, min_c);
    if (to_pad == 0 && min_c > 0)
        ft_putnbr_u_up(print, min_c);
    return (0);
}

int conv_uitoa(char *input, int index, int has_format, va_list args2)
{
    unsigned int a;
    int width;
    int min_c;
    int zero;
    if (has_format == -1)
    {
        a = va_arg(args2, unsigned int);
        ft_putnbr_u(a);
        return (ft_intstrchr_flag(input, 'u', index));
    }
    else
    {
        width = find_width(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        zero = ft_zerochr(input, index);
        a = va_arg(args2, unsigned int);
        format_u(a, width, min_c, zero);
        return (ft_intstrchr_flag(input, 'u', index));
    }
    return (FAIL);
}

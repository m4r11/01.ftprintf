/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:18:21 by user              #+#    #+#             */
/*   Updated: 2021/04/06 12:27:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int null_string(char *print, int to_pad, int min_c, int zero)
{
    print = "(null)";
    if (min_c > 0 && min_c <= ft_strlen(print))
    {
        ft_putstr_limit(print, min_c);
        print_x_times((to_pad * -1) - min_c, ' ');
        return (0);
    }
    if (min_c == 0 && to_pad < 0)
    {
        print_x_times((to_pad * -1), ' ');
        return (0);
    }
    if (min_c == -1 && to_pad > 0)
    {
        print_x_times((to_pad - ft_strlen(print)), ' ');
        ft_putstr(print);
        return (0);
    }
    else
    {
        ft_putstr(print);
        if (to_pad < 0)
        {
            print_x_times((to_pad * -1) - ft_strlen(print), ' ');
            return(0);
        }
        print_x_times(to_pad - ft_strlen(print), ' ');
    }
    return (0);
}

int pad_left_s(char *print, int to_pad, int min_c, int zero)
{
    if (min_c == 0)
    {
        print_x_times(to_pad, ' ');
        return (0);
    }
    if (to_pad > min_c && min_c > 0)
    {
        if (min_c > ft_strlen(print))
        {
            print_x_times(to_pad - ft_strlen(print), ' ');
            ft_putstr(print);
            return (0);
        }
        else
        {
            print_x_times(to_pad - min_c, ' ');
            ft_putstr_limit(print, min_c);
            return (0);
        }
        return (0);
    }
    if (min_c == -1)
    {
        if (to_pad == ft_strlen(print))
            print_x_times(to_pad - ft_strlen(print), ' ');
        else
            print_x_times(to_pad - ft_strlen(print), ' ');
        ft_putstr(print);
        return (0);
    }
    if( min_c > ft_strlen(print))
    {
        print_x_times(to_pad - ft_strlen(print), ' ');
        ft_putstr(print);
        return(0);
    }
    print_x_times(to_pad - min_c, ' ');
    if (min_c > 0)
        ft_putstr_limit(print, min_c);
    else
        ft_putstr(print);
    return (0);
}

int pad_right_s(char *print, int to_pad, int min_c, int zero)
{
    if (to_pad < 0 && min_c == -1)
    {
        if (ft_strlen(print) < (to_pad * -1))
        {
            ft_putstr(print);
            print_x_times((to_pad * -1) - ft_strlen(print), ' ');
            return (0);
        }
        print_x_times((to_pad * -1) - ft_strlen(print), ' ');
        ft_putstr(print);
        return (0);
    }
    if (to_pad < 0 && min_c > 0 && min_c <= ft_strlen(print))
    {
        ft_putstr_limit(print, min_c);
        print_x_times((to_pad * -1) - min_c, ' ');
        return (0);
    }
    ft_putstr(print);
    print_x_times((to_pad * -1) - ft_strlen(print), ' ');
    return (0);
}

int format_string(char *print, int to_pad, int min_c, int zero)
{
    if (print == NULL)
        return (null_string(print, to_pad, min_c, zero));
    if (to_pad > 0)
        return (pad_left_s(print, to_pad, min_c, zero));
    if (to_pad < 0)
        return (pad_right_s(print, to_pad, min_c, zero));
    if (to_pad == 0 && min_c == 0)
        return (0);
    if(min_c > ft_strlen(print))
        ft_putstr(print);
    else
        ft_putstr_limit(print, min_c);
    print_x_times((to_pad * -1) - ft_strlen(print), ' ');
    return (0);
}

int print_str(char *input, int index, int has_format, va_list args2)
{
    //debug_number(index, "index");
    char *print;
    int width;
    int min_c;
    int zero = ft_intstrchr(input, '0', index);
    if (has_format == -1)
    {
        if (!(print = va_arg(args2, char *)))
            print = "(null)";
        ft_putstr(print);
         return(ft_intstrchr_flag(input, 's', index));
    }
    else
    {
        width = find_width_c(input, index, args2);
        min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        print = va_arg(args2, char *);
        format_string(print, width, min_c, zero);
        return(ft_intstrchr_flag(input, 's', index));
    }
    return(FAIL);
}

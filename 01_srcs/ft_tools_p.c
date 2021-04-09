/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 21:29:21 by user              #+#    #+#             */
/*   Updated: 2021/04/09 18:07:31 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_pad_left_no_zero_p(long long print, int to_pad, int min_c)
{
    if (print == 0)
    {
        ft_put_address_up(print, min_c);
        print_x_times(to_pad - 3, ' ');
        return (0);
    }
    print_x_times(to_pad - ft_u_intlen(print), ' ');
    ft_put_address_up(print, min_c);
    return (0);
}

int ft_pad_left_big_pad_p(long long print, int to_pad, int min_c)
{
    if (print == 0)
    {
        print_x_times(to_pad - 3, ' ');
        ft_put_address_up(print, min_c);
        return (0);
    }
    if (print > 0)
    {
        print_x_times(to_pad - ft_hexlen(print), ' ');
        ft_put_address_up(print, min_c);
        return (0);
    }
    ft_put_address_up(print, min_c);
    print_x_times(to_pad - ft_u_intlen(print), ' ');
    return (0);
}

int ft_pad_right_nominc_p(long long print, int to_pad, int min_c)
{
    if (print == 0 || print == 1)
    {
        ft_put_address_up(print, min_c);
        print_x_times((to_pad * -1) - 3, ' ');
        return (0);
    }
    if (print < 0)
    {
        ft_put_address_up(print, min_c);
        print_x_times((to_pad * -1) - ft_u_intlen(print) - 1, ' ');
        return (0);
    }
    ft_put_address_up(print, min_c);
    print_x_times((to_pad * -1) - ft_hexlen(print), ' ');
    return (0);
}

int ft_edge_cases_p(long long print, int min_c)
{
    char *longmin;
    if (print == 0)
    {
        ft_putstr("0");
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 3, '0');
        return(0);
    }
    if (print == 1)
    {
        ft_putstr("1");
        if (min_c > 0 && print == 0)
            print_x_times(min_c - 3, '0');
        return(0);
    }
    if (print == LONG_MIN)
    {
        longmin = "8000000000000000";
        print_x_times(min_c - (ft_strlen(longmin)), '0');
        ft_putstr(longmin);
       return(0);
    }
    if (print == UINT_MAX + 1)
        ft_putc(' ');
    return(0);
}

void ft_min_c(long long print, int min_c, int len)
{
        if (ft_intlen(print) == 1)
            print_x_times(min_c - 1, '0');
        else
            print_x_times(min_c - len, '0');
        return;
}


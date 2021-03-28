/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_micro_tools.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:49:44 by user              #+#    #+#             */
/*   Updated: 2021/03/28 16:11:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_micro_great_width_less_print(int width, int min_c, int print, int len)
{
    print_x_times(width - (min_c + 1), ' ');
    ft_putc('-');
    print_x_times(min_c - (len - 1), '0');
    ft_putnbr(print * -1);
    return (0);
}

char ft_micro_great_width_great_len(int width, int min_c, int len)
{
    print_x_times(width - min_c, ' ');
    print_x_times(min_c - len, '0');
    return (0);
}

char ft_print_null(char *print, int width, int min_c)
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

char    ft_wrong_directive(char *dir, char *print, int width, int min_c)
{
        t_dir_variables dv;
        dv.new = ft_intstrchr(dir, '*', dv.start) + 1;
        dv.real = ft_intstrchr(dir, '%', dv.new) + 1;
        min_c = ft_atoi(&dir[dv.real + 1]);
        ft_putstr_limit(dv.print, dv.min_c);
        return (0);
}

char    ft_micro_same_len(char *print, int width, int min_c)
{
    if (width > (ft_strlen(print)))
        print_x_times(width - (ft_strlen(print)), ' ');
    ft_putstr(print);
    if (width < 0)
    {
        width *= -1;
        print_x_times(width - (ft_strlen(print)), ' ');
    }
    return (0);
}

char    ft_micro_less_len(char *print, int width, int min_c)
{
         if (width > (ft_strlen(print)))
            print_x_times(width - (ft_strlen(print)), ' ');
        ft_putstr(print);
        if (width < 0)
        {
            width *= -1;
            print_x_times(width, ' ');
        }
        return (0);
}

char    ft_micro_less_width(char *print, int width, int min_c)
{
        if (width < 0)
        {
            ft_putstr_limit(print, min_c);
            width *= -1;
            print_x_times(width - (min_c), ' ');
            return (0);
        }
        else
        {
            print_x_times(width - (min_c), ' ');
            ft_putstr_limit(print, min_c);
            return (0);
        }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:49:51 by user              #+#    #+#             */
/*   Updated: 2021/03/24 17:07:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char minor_len(int len, int min_c, int width, int print)
{
    if (width >= 0 && print >= 0)
    {

        print_x_times(width - min_c, ' ');
        print_x_times(min_c - len, '0');
        ft_putnbr(print);
        //ft_putc("👻");
        return (0);
    }
    if (width >= 0 && print < 0)
    {
        print_x_times(width - (min_c + 1), ' ');
        ft_putc('-');
        print_x_times(min_c - (len - 1), '0');
        ft_putnbr(print * -1);
        return (0);
    }
    if (width < 0 && print < 0)
    {
        width *= -1;
        print_x_times(width - (min_c + 1), ' ');
        ft_putc('-');
        print_x_times(min_c - (len - 1), '0');
        ft_putnbr(print * -1);
        return (0);
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

        print_x_times(width - min_c, ' ');
        print_x_times(min_c - len, '0');
        ft_putnbr(print);
    }
    if (width >= 0 && print < 0)
    {
        ft_putc('-');
        print_x_times(width - min_c, ' ');
        print_x_times(min_c - len, '0');
        ft_putnbr(print * -1);
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

char precision_op(int len, int min_c, int width, int print)
{
    if (len < min_c)
        return (minor_len(len, min_c, width, print));
    if (len >= min_c)
        return (greater_len(len, min_c, width, print));
    return(0);
}
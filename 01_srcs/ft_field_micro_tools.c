/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_micro_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:22:18 by user              #+#    #+#             */
/*   Updated: 2021/04/01 18:10:39 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    put_spaces_before_s(char *x1, int converted, int len)
{
    print_x_times(converted - len, ' ');
    ft_putstr(x1);
    return(0);
}

char    put_spaces_afer_s(char *x1, int converted, int len)
{
    ft_putstr(x1);
    print_x_times(converted - len, ' ');
    return(0);
}

char    put_spaces_before_c(int x, int converted)
{
    print_x_times(converted - 1, ' ');
    ft_putc(x);
    exit(0);
}

char    put_spaces_afer_c(int x, int converted)
{
    ft_putc(x);
    print_x_times(converted - 1, ' ');
    return(0);
}

char    put_spaces_before_x(long x, int converted)
{
    print_x_times(converted - 1, ' ');
    ft_put_x(x);
    return(0);
}

char    put_spaces_afer_x(long x, int converted)
{
    ft_put_x(x);
    print_x_times(converted - 1, ' ');
    return(0);
}
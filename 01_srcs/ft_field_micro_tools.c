/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_micro_field_tools.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:22:18 by user              #+#    #+#             */
/*   Updated: 2021/03/27 20:50:24 by user             ###   ########.fr       */
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
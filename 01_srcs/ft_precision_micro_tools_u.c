/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_micro_tools_u.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:38:58 by user              #+#    #+#             */
/*   Updated: 2021/03/31 19:05:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_micro_great_width_less_print_u(int width, int min_c, int print, int len)
{
    print_x_times(width - min_c , ' ');
    print_x_times(min_c - (len), '0');
    ft_putnbr_u(print);
    return (0);
}

char ft_micro_great_width_great_len_u(int width, int min_c, int len)
{
    //print_x_times(width - min_c, ' ');
    print_x_times(min_c - len, '0');
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:18:24 by user              #+#    #+#             */
/*   Updated: 2021/04/08 00:11:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_percent(char *input, int index, int has_format, va_list args2)
{
    static int count;
    t_dir_variables var;

    if (has_format == -1)
    {
        if (input[index + 1] == '%' /* && count % 2 == 0 */)
            ft_putc('%');
        count += 1;
        return (ft_intstrchr(input, '%', index));
    }
    else
    {
        var.to_pad = find_width_c(input, index, args2);
        var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        var.has_zero = ft_zerochr(input, index);
        int c = '%';
        format_c(c, var.to_pad, var.min_c, var.has_zero);
        return (ft_intstrchr(input, '%', index));
    }
}
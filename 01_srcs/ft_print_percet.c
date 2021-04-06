/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:18:24 by user              #+#    #+#             */
/*   Updated: 2021/04/06 09:43:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_percent(char *input, int index, int has_format, va_list args2)
{
    static int count;

    if (input[index + 1] == '%' /* && count % 2 == 0 */)
        ft_putc('%');
    count += 1;
    return(ft_intstrchr(input, '%', index));
}
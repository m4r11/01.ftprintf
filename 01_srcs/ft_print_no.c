/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_no.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:34:39 by user              #+#    #+#             */
/*   Updated: 2021/04/05 19:15:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_n(char *input,int index, int has_format, va_list args2)
{
    ft_putc('n');
    return(ft_intstrchr_flag(input, 'n', index));
}

int conv_otoa(char *input, int index,int has_format, va_list args2)
{
    ft_putc('8');
    return(ft_intstrchr_flag(input, '0', index));
}

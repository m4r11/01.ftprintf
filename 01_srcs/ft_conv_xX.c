/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_xX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/03/31 21:01:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_xtoa(char *input, int has_format, va_list args2)
{
    long q;
    if(has_format == -1)
    {
        q = va_arg(args2, int);
        ft_put_x(q);
        return;
    }
    return;
}

void conv_Xtoa(char *input, int has_format, va_list args2)
{
    long q;
    if(has_format == -1)
    {
        q = va_arg(args2, int);
        ft_put_X(q);
        return;
    }
    return;
}
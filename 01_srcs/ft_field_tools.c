/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:34:59 by user              #+#    #+#             */
/*   Updated: 2021/03/28 16:47:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    ft_minor_field_star_fetch(va_list args2, int x, int converted)
{
        x = va_arg(args2, int);
        converted = va_arg(args2, int);
        if (x >= 0)
        {
            ft_putc(converted);
            print_x_times(x - 1, ' ');
            return (0);
        }
        if (x < 0)
        {
            x *= -1;
            ft_putc(converted);
            print_x_times(x - 1, ' ');
            return (0);
        }
        return(0);
}

char    ft_copy(char *s1, char *s2)
{
    int i; 
    int j;
    int len;

    len = ft_strlen(s1);
    i = 0;
    j = 0;
    while(i < (len - 1) && j < len)
    {
        s2[j] = s1[i];
        i++;
        j++;
    }
    s2[j] = '\0';
    return(*s2);
}
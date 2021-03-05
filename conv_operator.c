/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:56 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/05 18:37:29 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* void (**get_converter[](char *s)
{
    if (arr[i].flag == c)
        return (arr[i].fptr);
    return (NULL);
}
 */

void ft_putstr(char *str);

void conv_itoa(char *format)
{
    ft_putstr("itoa");
}
void conv_xtoa(char *format)
{
    ft_putstr("xtoa");
}
void conv_uitoa(char *format)
{
    ft_putstr("utoa");
}
void conv_ftoa(char *format)
{
    ft_putstr("ftoa");
}
void conv_fetoa(char *format)
{
    ft_putstr("fetoa");
}
void conv_dtoa(char *format)
{
    ft_putstr("dtoa");
}

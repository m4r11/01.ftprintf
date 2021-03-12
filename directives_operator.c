/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directives_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:14:27 by user              #+#    #+#             */
/*   Updated: 2021/03/12 00:04:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"

void    put_position(char *dir)
{
        ft_putstr("-");
}
void    put_sign(char *dir)
{
        ft_putstr("+");
}
void    put_space(char *dir)
{
        ft_putstr("space");
}
void    put_zeroes(char *dir)
{
        ft_putstr("zeroes");
}
void    put_len(char *dir)
{
        ft_putstr("len");
}
void    put_dec_precision(char *dir)
{
        ft_putstr("presision");
}
void    put_alternate(char *dir)
{
        ft_putstr("0x");
}
void    put_field(char *dir)
{
        ft_putstr("field");
}
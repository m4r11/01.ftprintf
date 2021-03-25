/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deploy_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:14:27 by user              #+#    #+#             */
/*   Updated: 2021/03/25 18:56:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    put_position(char *dir,va_list args2, int flag)
{
        ft_putstr("-");
        return(0);
}
char    put_sign(char *dir,va_list args2, int flag)
{
        ft_putstr("+");
        return(0);
}
char    put_space(char *dir,va_list args2, int flag)
{
        ft_putstr("space");
         return(0);
}
char    put_zeroes(char *dir,va_list args2, int flag)
{
        if (flag = 8)
                return(0);     
         return(0);
}
char   put_len(char *dir,va_list args2, int flag)
{
        ft_putstr("len");
         return(0);
}

char    put_alternate(char *dir,va_list args2, int flag)
{
        printf("imhere");
        ft_putstr("0x");
         return(0);
}

/* Don't touch this */
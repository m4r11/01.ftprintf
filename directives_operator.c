/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directives_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:14:27 by user              #+#    #+#             */
/*   Updated: 2021/03/22 22:13:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"
/* 
char    put_star(char *dir, va_list args2, int flag)
{
    int x;
    int i;
    int value;
    int argnum;
    i = 0;
    x = va_arg(args2, int);
    value = va_arg(args2, int);
    argnum = arg_number(dir);

    while(dir[i])
    {
        if(dir[i] == 'c' && x >= 0)
        {
            //debug_number(dir[i], "dir inside while+");
            print_x_times(x - 1, ' ');
            ft_putc(value);
            //debug_number(value, "value+");
            break;
        }
        if (dir[i] == 'c' && x < 0)
        {
            //debug_number(dir[i], "dir inside while-");
            x *= -1;
            ft_putc(value);
            print_x_times(x -1, ' ');
            //debug_number(value, "value-");
            break;
        }
        i++;
    }
     return(0); 
} */

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
        ft_putstr("zeroes");
         return(0);
}
char   put_len(char *dir,va_list args2, int flag)
{
        ft_putstr("len");
         return(0);
}
/* char    put_dec_precision(char *dir,va_list args2, int flag)
{
        ft_putstr("presision");
         return(0);x
} */
char    put_alternate(char *dir,va_list args2, int flag)
{
        printf("imhere");
        ft_putstr("0x");
         return(0);
}

/* Don't touch this */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deploy_n_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:55:42 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/02 19:12:22 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  fptrdir get_dir[] =
    {
        &put_star, /* handles csdi for now */
        &put_position, /* handles hex and pointer field specs */
        &put_sign,
		&put_sign,
        &put_zeroes,
        &put_len,   /* h */
		&put_len,   /* l */
		&put_len,   /* j */
		&put_len,   /* z */
        &put_dec_precision, /* handles csdi for field specs plus combos */
        &put_alternate,
        &put_field, /* handles csdi for field specs */
};

char has_formating(char *format, int n, va_list args2, int flag)
{
    if(n == NO_FORMAT)
        return(0);
/* s */
    if (n == FIELD && flag == p)
        return(get_dir[POSITION](format, args2, flag));
    if (n >= FIELD)
        return(get_dir[FIELD](format, args2, flag));
    else
        return(get_dir[n](format, args2, flag));  
    return(0);
}

/* 
** string to fetch dir
** DIR_S "*-+ 0hljz.#123456789" 
*/

char    put_position(char *dir,va_list args2, int flag)
{
        return(position_address(dir, args2));
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
        if (flag == 8)
                return(0);
        if(flag == 2)
                return(field_x(dir, args, flag));
        if(flag == 4)
                return(field_u(dir, args));
         if (flag == 0 || flag == 1)
                return(put_field(dir, args2, flag));    
         return(0);
}
char    put_len(char *dir,va_list args2, int flag)
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
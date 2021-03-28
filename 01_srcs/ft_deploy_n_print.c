/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deploy_n_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:55:42 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/27 21:49:22 by user             ###   ########.fr       */
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
        &put_len,
		&put_len,
		&put_len,
		&put_len,
        &put_dec_precision, /* handles csdi for field specs plus combos */
        &put_alternate,
        &put_field, /* handles csdi for field specs */
};

char *has_formating(char *format, int n, va_list args2, int flag)
{
    if(n == NO_FORMAT)
        return(0);
    if (n == FIELD && flag == p)
        return(get_dir[POSITION](format, args2, flag));
    if (n >= FIELD)
        return(get_dir[FIELD](format, args2, flag));
    else
        return(get_dir[n](format, args2, flag));  
    return(0);
}
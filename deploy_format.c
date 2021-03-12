/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:55:42 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/12 00:04:34 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"

static  fptrdir get_dir[] =
    {
        &put_position,
        &put_sign,
		&put_sign,
        &put_zeroes,
        &put_len,
		&put_len,
		&put_len,
		&put_len,
        &put_dec_precision,
        &put_alternate,
        &put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
		&put_field,
};

char *has_formating(char *format, int n)
{
    get_dir[n](format);
    printf("%c", format[n+1]);
return(0);
}

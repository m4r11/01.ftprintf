/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deploy_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:55:42 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/10 19:41:47 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  fp_directives g_dir[] =
{
        &put_spaces;
        &put_zeroes;
        &
}

void has_formating(char *format, char *directions)
{
    int i;
    i = 0;
    while (*format != '\0' && *directions != '\0')
    {
        directions[i++];
        if(directions == format)
{

}
    }
}
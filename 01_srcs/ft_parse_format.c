/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:10:36 by user              #+#    #+#             */
/*   Updated: 2021/03/24 15:20:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_for_directives(char *flags, char *format, int j)
{
    int i;
    char found;
    char *start = (ft_strchr(&format[j], '%') + 1);
    //debug_str(start, "start");
    int argnum;
    int f;
    f = 0;
    argnum = arg_number(format);
    
    if(start[0] == '*')
        return(STAR);
    if(start[0] == '-')
        return(FIELD);
    if(start[0] == '+')
        return(SIGN);
    if(start[0] == ' ')
        return(SPACESIGN);
    if(start[0] == '0')
        return(ZERO);
    if(start[0] == 'h')
        return(SHORT);
    if(start[0] == 'l')
        return(LONG);
    if(start[0] == '.')
        return(PRECISION);
    if(start[0] == '#')
        return(ALTERNATE);
    if(start[0] == '1')
        return(FIELD);
    if(start[0] == '2')
        return(FIELD);
    if(start[0] == '3')
        return(FIELD);
    if(start[0] == '4')
        return(FIELD);
    if(start[0] == '5')
        return(FIELD);
    if(start[0] == '6')
        return(FIELD);
    if(start[0] == '7')
        return(FIELD);
    if(start[0] == '8')
        return(FIELD);
    if(start[0] == '9')
        return(FIELD);
    else 
        return(-1);
    return(0);
}

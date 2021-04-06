/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_flag_n_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:40 by user              #+#    #+#             */
/*   Updated: 2021/04/06 09:21:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_through(char *flags, char *format, int j)
{
    int i;
    if (format[j + 1] == 'i')
        return(1);
    if(format[j + 1] == '%')
        return(15);
    while(format[j] != END_DIR)
    {
        if (format[j] == CONV_S[f])
            j+=1;
        i = 0;
        while (flags[i] != format[j] && flags[i] != '\0')
        {
            //debug_str(&flags[i], "flags");
            i+=1;
        }
   /*      debug_number(i, "I");
        debug_number(j, "J"); */
        if (flags[i] == format[j])
        {
            return(i);
                break;
        }
        else 
            i = 0; 
            j+=1;
      /*       debug_number(i, "i");
            debug_number(j, "j"); */
    }
return(-3);
}

int    loop_for_directives(char *flags, char *format, int j)
{
    char *start = (ft_strchr(&format[j], '%') + 1);
    //debug_str(start, "start");
    int argnum;
    
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
    if(ft_isdigit(start[0]))
        return(FIELD);
    else 
        return(-1);
}

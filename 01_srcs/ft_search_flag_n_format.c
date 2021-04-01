/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_flag_n_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:53:40 by user              #+#    #+#             */
/*   Updated: 2021/04/01 08:57:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    loop_through(char *flags, char *format, int j)
{
    int i;

    if (format[j +1] == 'i')
        return(1);

    while(format[j] != END_DIR)
    {
        //debug_str(&format[j], "format");
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
return(-1);
}

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

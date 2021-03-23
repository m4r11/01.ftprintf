/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:59:38 by user              #+#    #+#             */
/*   Updated: 2021/03/23 22:39:07 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_c_combos(char *dir,va_list args2)
{
        int i;
        int j;
        int len;
        int x;
        char to_convert[500];
        int converted;
        char *temp = (ft_strchr(dir, '%') + 1);
        len = ft_strlen(temp);
        
        //debug_str(temp, "temp");
        if (temp[0] == '-' && temp[1] == '*')
        {
           x = va_arg(args2, int);
           converted = va_arg(args2, int);
            if (x >= 0)
            {
                ft_putc(converted);
                print_x_times(x- 1, ' ');
             return(0);
            }
            if (x < 0)
            {

                x *= -1;
                ft_putc(converted);
                print_x_times(x -1, ' ');
            return(0);
            }
       
        }
        return(0);
}

char field_s(char *dir,va_list args2)
{
        int i;
        int j;
        int len;
        char *x1;
        int x1converted;
        int x1len;
        char to_convert[500];
        int converted;
        char *temp = (ft_strchr(dir, '%') + 1);
        len = ft_strlen(temp);
/* 
        if (temp[0] == '-' && temp[1] == '*')
            field_s_combos(dir, args2);  */
        i = 0;
        j = 0;
        while (i < (len-1) && j < len)
        {
            to_convert[j] = temp[i];
            i++;
            j++;
        } 
        to_convert[j] = '\0';
        converted = ft_simple_atoi(to_convert); 
        x1 = va_arg(args2, char*);
        x1converted = ft_simple_atoi(x1);
        x1len = ft_intlen(x1converted);
        if (temp[0] == '-')
        {
     /*        debug_number(converted, "x"); 
            debug_number(x1converted, "x1");  */
            //debug_str(x1, "x1");
            ft_putstr(x1);
            print_x_times(converted - x1len , ' ');     
        }
        else 
        {
            print_x_times(converted , ' ');
            ft_putstr(x1);
            exit(0);
        }
    return(0);
}


char    put_field(char *dir,va_list args2, int flag)
{
    //debug_number(flag, "flag");
        int i;
        int j;
        int len;
        int x;
        char *x1;
        char to_convert[500];
        int converted;
        char *temp = (ft_strchr(dir, '%') + 1);
        len = ft_strlen(temp);

       //debug_str(temp, "t");
        if (temp[0] == '-' && (temp[1] == '.' || temp[2] == '.' || temp[3] == '.'))
        {
            precision_int(dir, args2);
            return(0);
        }
        if ((ft_isdigit(temp[0]) == 1) && (temp[1] == '.' || temp[2] == '.' || temp[3] == '.'))
        {
            precision_int(dir, args2);
            return(0);
        }

        if (temp[0] == '-' && temp[1] == '*')
            field_c_combos(dir, args2); 
       if (flag == 8)
            return(field_s(dir,args2));
        i = 0;
        j = 0;
        while (i < (len-1) && j < len)
        {
            to_convert[j] = temp[i];
            i++;
            j++;
        } 
        to_convert[j] = '\0';
        converted = ft_simple_atoi(to_convert);
        x = va_arg(args2, int);
        if (temp[0] == '-')
        {
            ft_putc(x);
            print_x_times(converted - 1, ' ');  
        }
        else 
        {
            print_x_times(converted , ' ');
            ft_putc(x);
            exit(0);
        }
    return(0);
}



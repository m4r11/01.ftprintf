/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:18:21 by user              #+#    #+#             */
/*   Updated: 2021/04/01 08:25:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_str(char *input, int has_format, va_list args2)
{
    char *print;
    if( has_format == -1)
    {
        //debug_str(input, "input")o -4 n e daqui;
        print = va_arg(args2, char *);
        ft_putstr(print);
    }
     else 
        return ;
}

/*
** dv. stands for "directives variables" stored in opaque typedef t_dir_variables in printf.h
*/

char field_s(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%'));
    dv.verify = ft_strchr(dir, '.');
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    if (dv.verify && (ft_isdigit(dv.verify[1]) || dv.verify[1] == '-'))
        return (precision_s(dir, args2));
    dv.converted = ft_simple_atoi(&to_convert[pin + 1]);
    pin = ft_intstrchr(dir, '%', pin);
    dv.x1 = va_arg(args2, char *);
    if (dv.x1 == NULL)
        return (precision_s(dir, args2));
    dv.x1converted = ft_simple_atoi(dv.x1);
    dv.x1len = ft_intlen(dv.x1converted);
    if (dv.verify && dv.verify[1] == 's')
        return (print_x_times(dv.converted, ' '));
    if (dv.temp[1] == '-')
        return (put_spaces_afer_s(dv.x1, dv.converted, dv.x1len));
    else
        return (put_spaces_before_s(dv.x1, dv.converted, dv.x1len));
    return (0);
}

char star_s(char *dir, va_list args2)
{
    int x;
    int i;
    char *value;
    int argnum;
    int start;
    int min_c;

    i = 0;
    start = ft_intstrchr_flag(dir, '%', 0);

    x = va_arg(args2, int);
    //debug_number(x, "x");
    value = va_arg(args2, char *);
    argnum = arg_number(dir);
/*     debug_str(dir, "dir");
    debug_number(start, "start"); */
    if (value == NULL)
    {
        ft_putstr("(null)");
            return(0);
    }
    while (dir[i])
    {
        if (dir[start + 3] == '0')
        {
            print_x_times(x + 1, ' ');
            break;
        }
        if (dir[start + 2] == '.' && dir[start + 3] == 's')
        {
            print_x_times(x, ' ');
            break;
        }
        if (dir[start + 1] == '*' && dir[start + 2] == '.')
        {
            min_c = ft_simple_atoi(&dir[start + 3]);
            if (x < 0)
            {
                if (ft_strlen(value) == min_c)
                {
                    x *= -1;
                    ft_putstr(value);
                    print_x_times(x - ft_strlen(value), ' ');
                    break;
                }
                else
                {
                     if (ft_strlen(value) < min_c)
                    {
                        x *= -1;
                        ft_putstr(value);
                        print_x_times(x - ft_strlen(value), ' ');
                        //print_x_times(min_c - ft_strlen(value), ' ');
                        break;
                    }
                    else 
                    {
                        x *= -1;
                        /* todo: another if like (ft_strlen(value) < min_c) */
                        ft_putstr_limit(value, min_c);
                        print_x_times(x - ft_strlen(value), ' ');
                        break;
                    }
                }
            }
            else
            {
                if (ft_strlen(value) == min_c)
                {
                    print_x_times(x - ft_strlen(value), ' ');
                    ft_putstr(value);
                    break;
                }
                else
                {
                    if (ft_strlen(value) < min_c)
                    {
                        print_x_times(x - (ft_strlen(value)), ' ');
                        //print_x_times(min_c - ft_strlen(value), ' ');
                        ft_putstr(value);
                        break;
                    }
                    else 
                    {
                        print_x_times(x - ft_strlen(value), ' ');
                        ft_putstr_limit(value, min_c);
                        break;
                    }
                }
            }
            break;
        }
        if (x >= 10)
        {
            //debug_number(dir[i], "dir inside while+");
            print_x_times(x - ft_strlen(value), ' ');
            ft_putstr(value);
            break;
        }
        if (x >= 0 && x < 10)
        {
            print_x_times(x - ft_strlen(value), ' ');
            ft_putstr(value);
            break;
        }
        if (x < 0)
        {
            //debug_number(dir[i], "dir inside while-");
            x *= -1;
            ft_putstr(value);
            print_x_times(x - ft_strlen(value), ' ');
            //debug_number(value, "value");
            break;
        }
        i++;
    }
    return (0);
}
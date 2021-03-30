/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:52:37 by user              #+#    #+#             */
/*   Updated: 2021/03/30 15:41:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char put_star(char *dir, va_list args2, int flag)
{
    int x;
    int value;
    int argnum;
    static int real;
    int start = ft_intstrchr_flag(dir, '*', real);

    //debug_str(dir, "dir");
    if (flag == 8)
        return (star_s(dir, args2));
    if (flag == 13)
        return (position_address(dir, args2));
    if (dir[2] == '.' || dir[3] == '.')
    {
        return (precision_int_combos(dir, args2, flag));
    }
    if (flag == 4)
    {
          x = va_arg(args2, int);
          value = va_arg(args2, unsigned int);
          if(x < 0)
          {
                x *= -1;
                ft_putnbr_u(value);
                print_x_times(x - 1, ' ');
            return (0);
          }
          if(x >= 0)
          {
            print_x_times(x - 1, ' ');
            ft_putnbr_u(value);
            return (0);
          }
          return(0);
    }
    x = va_arg(args2, int);
    value = va_arg(args2, int);
    argnum = arg_number(dir);
    if ((dir[start + 1] == 'c' || dir[start + 1] == 'd' || dir[start + 1] == 'i') && x >= 0)
    {
        //printf("cute program here\n");
        print_x_times(x - 1, ' ');
        ft_putc(value);
        return (0);
    }
    if ((dir[start + 1] == 'c' || dir[start + 1] == 'd' || dir[start + 1] == 'i') && x < 0)
    {
        x *= -1;
        ft_putc(value);
        print_x_times(x - 1, ' ');
        return (0);
    }
    return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:52:37 by user              #+#    #+#             */
/*   Updated: 2021/04/01 08:25:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
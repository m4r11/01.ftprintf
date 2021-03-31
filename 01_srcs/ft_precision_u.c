/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:21:15 by user              #+#    #+#             */
/*   Updated: 2021/03/31 19:55:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char precision_u(char *dir, va_list args2)
{
    static int position;
    static int real;
    int min_c;
    unsigned int print;
    int width;
    int start;
    t_dir_variables dv;

    start = ft_intstrchr_flag(dir, '%', position);
    if (dir[start + 1] == '-' && dir[start + 2] == '*' && dir[start + 3] == '.')
        return (precision_u_combos(dir, args2));
    real = (ft_intstrchr(dir, '.', start));
    if(dir[real + 1] == 'u')
        return(field_u_combos(dir, args2));
    width = find_width(dir, start);
    min_c = ft_atoi(&dir[real + 1]);
    position += 1;
    print = va_arg(args2, unsigned int);
    int len = ft_u_intlen(print);
    if (real == -1 && width == 0)
        return (0);
   /*  if (print < -100000000 || print > 100000000)
        return (0); */
    if ((min_c == 0 && ft_isalpha(dir[real])) || real == -1)
        return (0);
    if (width == 0 && min_c == 0 && print != 0)
        ft_putnbr_u(print);
    if (print == 0 && min_c == 0)
    {
        print_x_times(width, ' ');
        return (0);
    }
    precision_op_u(len, min_c, width, print);
    position += real;
    return (0);
}
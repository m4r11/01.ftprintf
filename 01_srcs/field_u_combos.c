/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_u_combos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 20:28:14 by user              #+#    #+#             */
/*   Updated: 2021/03/31 20:17:04 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char field_u_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    //debug_str(dv.temp, "t");
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
    {
        if (dv.temp[2] == '*' && dv.temp[3] == '.' && dv.temp[4] == '*')
        {
            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, int);
            if (dv.min_c > dv.width)
            {
                print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            }
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.temp[2] == '*' && (dv.temp[3] == 'u' || dv.temp[3] == 'u')) /* || dv.temp[3] == 'i' || dv.temp[3] == 'u') */
        {
            dv.width = va_arg(args2, int);
            dv.x = va_arg(args2, int);
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        return (0);
    }
    if (dv.temp[0] == '-' && dv.temp[1] == '0' && dv.temp[2] == '*')
    {
        dv.width = va_arg(args2, int);
        dv.min_c = ft_atoi(&to_convert[4]);
        dv.x = va_arg(args2, unsigned int);
        //debug_number(dv.width, "w");
/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        ft_printf("this is u :%u", dv.x); */
        if (dv.width < 0 && dv.x < 0)
        {
            /*dont touch this */
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            print_x_times((dv.width *= -1) - ft_u_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.width < 0 && dv.x >= 0)
        {
            /*dont touch this */
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            dv.width *= -1;
            if (dv.min_c < ft_u_intlen(dv.x))
            {
                print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
                return (0);
            }
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        if (dv.width > 0 && dv.x < 0)
        {
            if (dv.min_c == 0)
            {
                ft_putnbr_u(dv.x);
                print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
                return (0);
            }
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            if (dv.min_c < ft_u_intlen(dv.x))
            {
                print_x_times(dv.width - ft_u_intlen(dv.x) - 1, ' ');
                return (0);
            }
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        if (dv.min_c == 0)
        {
            /*dont touch this */
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.width > 0 && dv.min_c > 0 && dv.x > 0)
        {
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        else
        {
            /* martelada fix this  */
            print_x_times(dv.min_c, '0');
            print_x_times(dv.width - dv.min_c, ' ');
            return(0);
        }
        return(0);
    }
    /* ->| %-0*.2u*0 |<-  */
    if (dv.temp[0] == '-' && dv.temp[1] == '0' && dv.temp[2] == '*' && dv.temp[3] == '.' && ft_isdigit(dv.temp[4]))
    {
        dv.width = va_arg(args2, int);
        dv.min_c = ft_atoi(&to_convert[4]);
        dv.x = va_arg(args2, unsigned int);
        
/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "m"); */
        if (dv.width < 0 && dv.x < 0)
        {
            /*dont touch this */
            ft_putc('-');
            dv.x *= -1;
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x);
            print_x_times(dv.width - dv.min_c - ft_intlen(dv.x) - 1, ' ');
            return (0);
        }
        if (dv.width < 0 && dv.x >= 0)
        {
            /*dont touch this */
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x);
            dv.width *= -1;
            if (dv.min_c < ft_intlen(dv.x))
            {
                print_x_times(dv.width - ft_intlen(dv.x), ' ');
                return (0);
            }
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        if (dv.width > 0 && dv.x < 0)
        {
            if (dv.min_c == 0)
            {
                ft_putnbr_u(dv.x);
                print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
                return (0);
            }
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            if (dv.min_c < ft_u_intlen(dv.x))
            {
                print_x_times(dv.width - ft_u_intlen(dv.x) - 1, ' ');
                return (0);
            }
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        if (dv.min_c == 0)
        {
            /*dont touch this */
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.width >= 0 && dv.min_c > 0 && dv.x > 0)
        {
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x);
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        print_x_times(dv.min_c, '0');
        print_x_times(dv.width - dv.min_c , ' ');
        return(0);
    }

   /*  %-.2u  */
    if(dv.temp[0] == '-' && dv.temp[1] == '.')
    {
        dv.x = va_arg(args2, unsigned int);
        dv.min_c = ft_atoi(&dv.temp[2]);
        //debug_number(dv.min_c, "m");
        if(dv.x == 0)
        {
            print_x_times(dv.min_c, '0');
            return(0);
        }
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        return(0);      
    }
    if(dv.temp[0] == '-' && dv.temp[1] == '*')
    {
        //printf("here");
        dv.width = va_arg(args2, int);
        dv.min_c = va_arg(args2, int);
        dv.x = va_arg(args2, unsigned int);
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        if (dv.width > dv.min_c)
        {
            print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
        }
         return(0);
    }
    if(dv.temp[0] == '-')
    {
        dv.x = va_arg(args2, unsigned int);
        dv.width = ft_atoi(&dv.temp[1]);
        dv.min_c = ft_atoi(&dv.temp[3]);
        //debug_number(dv.min_c, "m");
         if(dv.x == 0)
        {
            print_x_times(dv.min_c, '0');
            print_x_times(dv.width - dv.min_c, ' ');
            return(0);
        }
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        print_x_times(dv.width - dv.min_c, ' ');
        return(0);
    }
    if(ft_isdigit(dv.temp[0]))
    {
        dv.x = va_arg(args2, unsigned int);
        dv.width = ft_atoi(&dv.temp[0]);
        dv.min_c = ft_atoi(&dv.temp[2]);
        if(dv.x == 0)
        {
            print_x_times(dv.min_c, '0');
            print_x_times(dv.width, ' ');
            return(0);
        }
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        print_x_times(dv.width - dv.min_c, ' ');
        return(0);
    }
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
    {
        if (dv.temp[2] == '*' && dv.temp[3] == '.' && dv.temp[4] == '*')
        {
            dv.width = va_arg(args2, int);
            dv.min_c = va_arg(args2, int);
            dv.x = va_arg(args2, unsigned int);
            if (dv.min_c > dv.width)
            {
                print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            }
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.temp[2] == '*' && (dv.temp[3] == 'd' || dv.temp[3] == 'i')) /* || dv.temp[3] == 'i' || dv.temp[3] == 'u') */
        {
            dv.width = va_arg(args2, int);
            dv.x = va_arg(args2, unsigned int);
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        return (0);
    }
    if (dv.temp[0] == '-' && dv.temp[1] == '0' && dv.temp[2] == '*')
    {

        dv.width = va_arg(args2, int);
        dv.min_c = ft_atoi(&to_convert[4]);
        dv.x = va_arg(args2, unsigned int);
        if (dv.width < 0 && dv.x < 0)
        {
            /*dont touch this */
            ft_putc('-');
            dv.x *= -1;
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - dv.min_c - ft_intlen(dv.x) - 1, ' ');
            return (0);
        }
        if (dv.width < 0 && dv.x >= 0)
        {
            /*dont touch this */
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            dv.width *= -1;
            if (dv.min_c < ft_intlen(dv.x))
            {
                print_x_times(dv.width - ft_intlen(dv.x), ' ');
                return (0);
            }
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        if (dv.width > 0 && dv.x < 0)
        {
            /*dont touch this 19 */
            ft_putc('-');
            // debug_number(dv.min_c, "m");
            if (dv.min_c == 0)
            {
                dv.x *= -1;
                ft_putnbr_u(dv.x);
                print_x_times(dv.width - ft_intlen(dv.x) - 1, ' ');
                return (0);
            }
            dv.x *= -1;
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            if (dv.min_c < ft_intlen(dv.x))
            {
                print_x_times(dv.width - ft_intlen(dv.x) - 1, ' ');
                return (0);
            }
            print_x_times(dv.width - dv.min_c - 1, ' ');
            return (0);
        }
        if (dv.min_c == 0)
        {
            /*dont touch this */
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.width > 0 && dv.min_c > 0 && dv.x > 0)
        {
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - dv.min_c, ' ');
            return (0);
        }
        /*       debug_number(dv.width, "w");
        debug_number(dv.min_c, "m");
        debug_number(dv.x, "x"); */
    }
    return (0);
}

/*         debug_number(dv.width, "w");
        debug_number(dv.min_c, "min_c");
        debug_number(dv.x, "x"); */

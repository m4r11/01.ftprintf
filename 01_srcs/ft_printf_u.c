/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:38:53 by user              #+#    #+#             */
/*   Updated: 2021/04/01 15:46:46 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void conv_uitoa(char *input, int has_format, va_list args2)
{
    /* unsigned int x; */
    unsigned int a;
    if (has_format == -1)
    {
        a = va_arg(args2, unsigned int);
        ft_putnbr(a);
    }
    else 
        return ;
}

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

/* handles " *%-*.*u* *%-*.*u* " */
char precision_u_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;
   //printf("imhere");

    dv.temp = (ft_strchr(&dir[pin], '%')) + 1;
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    dv.width = va_arg(args2, int);
    dv.min_c = va_arg(args2, int);
    dv.x = va_arg(args2, unsigned int);
    dv.len = ft_u_intlen(dv.x);

    if(dv.min_c > dv.width && dv.width > 0)
    {
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        return(0);
    }
    if(dv.min_c < (dv.width * -1) && dv.width < 0)
    {
        dv. width *= -1;
        ft_putnbr_u(dv.x);
        print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
        return(0);
    }

    return(0);
}

char field_u(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    pin = ft_intstrchr(dir, '%', pin);

    /*   debug_str(dv.temp, "temp"); */
    /* ->| %0- |<-  */
    if (dv.temp[0] == '0' && dv.temp[1] == '-')
        return (zero_u_combos(dir, args2));
        /* ->| %0* |<-  */
    if (dv.temp[0] == '0' && dv.temp[1] == '*')
        return (zero_u_combos(dir, args2));
    /* ->| %-0 |<-  */
    if (dv.temp[0] == '-' && dv.temp[1] == '0')
        return (field_u_combos(dir, args2));
    /* ->| %0. |<-  */
    if (dv.temp[0] == '0' && dv.temp[2] == '.')
        return (zero_u_combos(dir, args2));
    /* ->| %01 |<-  */
    if (dv.temp[0] == '0' && ft_isdigit(dv.temp[1]))
        return (zero_u_combos(dir, args2));
    /* ->| %-* |<-  */
    if (dv.temp[0] == '-' && dv.temp[1] == '*')
        return (field_u_combos(dir, args2));
    /* ->| %-1. || % 10. |<-  */
    if (((dv.temp[0] == '-' || ft_isdigit(dv.temp[0]) == 1) && dv.temp[1] == '.') ||
        dv.temp[2] == '.' || dv.temp[3] == '.')
        return (precision_u(dir, args2));       
    /* ->| else |<-  */
    ft_copy(dv.temp, to_convert);
    dv.converted = ft_simple_atoi(to_convert);
    dv.x = va_arg(args2, unsigned int);
    if (dv.temp[0] == '-')
        return (put_spaces_afer_u(dv.x, dv.converted));
    else
        return (put_spaces_before_u(dv.x, dv.converted));
    return (0);
}

char field_u_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_u_combos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 11:46:09 by user              #+#    #+#             */
/*   Updated: 2021/03/31 20:04:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char zero_u_combos(char *dir, va_list args2)
{
    static int pin;
    char to_convert[500];
    t_dir_variables dv;

    dv.temp = (ft_strchr(&dir[pin], '%') + 1);
    dv.len = ft_strlen(dv.temp);
    ft_copy(dv.temp, to_convert);
    pin = ft_intstrchr(dir, '%', pin);
    if (dv.temp[1] == '-')
    {

        if (dv.temp[2] == '*' && dv.temp[3] == '.' && dv.temp[4] == '*')
            return (zero_minus_star_dot_star_u(args2));
        if (dv.temp[2] == '*')
            return (zero_star_u(args2));
        dv.temp = (ft_strchr(dv.temp, '%') + 1);
            return(0);
    }
    if ((dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == 'u' )|| dv.temp[3] == 'u')
        return ( zero_simple_star_u(args2));
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == '.' && dv.temp[3] == '*')
        return (zero_star_dot_star_u(args2));
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && dv.temp[2] == '.' && ft_isdigit(dv.temp[3]))
        return (zero_star_dot_digi_u(args2, to_convert));
    /* ->| %0*d |<- */
    if (dv.temp[0] == '0' && dv.temp[1] == '*' && (dv.temp[2] == 'u' || dv.temp[2] == 'u'))
        return (zero_star_flag_u(args2));
    /* ->| %010.4d |<- */
    if (ft_isdigit(dv.temp[1]) && ft_isdigit(dv.temp[2]) && dv.temp[3] == '.' && ft_isdigit(dv.temp[4]))
        return(zero_2digi_dot_flag_u(args2, to_convert));
    /* ->| %01.4d |<- */
    if (dv.temp[2] == '.' && ft_isdigit(dv.temp[3]))
        return(zero_1digit_dot_flag_u(args2, to_convert));
return (0);
}

/* ->| %0*u |<- */
char zero_simple_star_u(va_list args2)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.x = va_arg(args2, unsigned int);
    print_x_times(dv.width - ft_u_intlen(dv.x), '0');
    ft_putnbr_u(dv.x);
    return (0);
}
/* ->| %0-*u |<- */
char zero_star_u(va_list args2)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.x = va_arg(args2, unsigned int);
    ft_putnbr_u(dv.x);
    print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
    return (0);
}
/* ->| %0-*.* |<- */
char zero_minus_star_dot_star_u(va_list args2)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.min_c = va_arg(args2, int);
    dv.x = va_arg(args2, unsigned int);
    if (dv.width > dv.min_c)
    {
        print_x_times(dv.min_c - dv.min_c, '0');
        ft_putnbr_u(dv.x);
        print_x_times(dv.width - dv.min_c -1, ' ');
        return (0);
    }
    print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
    ft_putnbr_u(dv.x);
    return (0);
}

/* ->| %0*.* |<- */
char zero_star_dot_star_u(va_list args2)
{

    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.min_c = va_arg(args2, int);
    dv.x = va_arg(args2, unsigned int);
    if (dv.width > dv.min_c)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.min_c - dv.min_c, '0');
        ft_putnbr_u(dv.x);
        return (0);
    }
    print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
    ft_putnbr_u(dv.x);
    return (0);
}
/* ->| %0*.0 |<- */
char zero_star_dot_digi_u(va_list args2, char *to_convert)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.min_c = ft_atoi(&to_convert[3]);
    dv.x = va_arg(args2, int);
    /*     debug_number(dv.width, "w");
    debug_number(dv.min_c, "m");
    debug_number(dv.x, "x"); */
    if (dv.x == INT_MAX)
    {
        ft_putnbr(dv.x);
        if (dv.width < 0)
            dv.width *= -1;
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        return (0);
    }
    if (dv.x == INT_MIN)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        ft_putnbr_u(dv.x);
        return (0);
    }
    if (dv.width > dv.min_c && dv.x < 0)
    {
        print_x_times(dv.width - dv.min_c - 1, ' ');
        return (0);
    }
    if (dv.x < 0)
    {
        //ft_printf("here");
        ft_putnbr_u(dv.x);
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        if (dv.width < 0)
            dv.width *= -1;
        print_x_times(dv.width - ft_u_intlen(dv.x),' ');
        return (0);
    }
    if (dv.x >= 0 && dv.width > 0)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.min_c - ft_intlen(dv.x), '0');
        ft_putnbr(dv.x);
        return (0);
    }
    if (dv.x == 0 && dv.width < 0)
    {
        dv.width *= -1;
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.width > dv.min_c)
    {
        if (dv.x > 0)
        {
            print_x_times(dv.width - dv.min_c, ' ');
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x);
            return (0);
        }
        if (dv.x < 0)
        {
            ft_putc('-');
            print_x_times(dv.width - dv.min_c, ' ');
            print_x_times(dv.min_c - ft_intlen(dv.x), '0');
            ft_putnbr(dv.x * -1);
            return (0);
        }
        return (0);
    }
    print_x_times(dv.min_c - ft_intlen(dv.x), '0');
    ft_putnbr(dv.x);
    return (0);
}
/* ->| %0*d |<- */
char zero_star_flag_u(va_list args2)
{
    t_dir_variables dv;
    dv.width = va_arg(args2, int);
    dv.x = va_arg(args2, int);
    if (dv.x < 0)
    {
        dv.x *= -1;
        ft_putc('-');
    }
    print_x_times(dv.width - ft_intlen(dv.x) - 1, '0');
    ft_putnbr(dv.x);
    return (0);
}
/* ->| %010.4d |<- */
char zero_2digi_dot_flag_u(va_list args2, char *to_convert)
{
    t_dir_variables dv;
    dv.width = ft_atoi(&to_convert[1]);
    dv.min_c = ft_atoi(&to_convert[4]);
    dv.x = va_arg(args2, unsigned int);
    
    if (dv.width == dv.min_c)
    {
        if (dv.x < 0)
        {
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            return (0);
        }
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        return (0);
    }
    if (dv.x == 0 && dv.min_c == 0 && dv.width > 0)
    {
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.min_c == 0 && dv.width > 0)
    {
        print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
        ft_putnbr_u(dv.x);
        return (0);
    }
    if (dv.min_c > 0 && dv.min_c < ft_intlen(dv.x))
    {
        print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
        ft_putnbr_u(dv.x);
        return (0);
    }
    if (dv.min_c > 0 && dv.min_c >= ft_intlen(dv.x))
    {
        if (dv.x < 0)
        {
            print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
            print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
            ft_putnbr_u(dv.x);
            return (0);
        }
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        return (0);
    }
    return (0);
}
/* ->| %01.4d |<- */
char zero_1digit_dot_flag_u(va_list args2, char *to_convert)
{
    t_dir_variables dv;
    dv.width = ft_atoi(&to_convert[1]);
    dv.min_c = ft_atoi(&to_convert[3]);
    dv.x = va_arg(args2, unsigned int);
/*     debug_number(dv.width, "w");
    debug_number(dv.min_c, "m");
    debug_number(dv.x, "x");
    debug_number(ft_intlen(dv.x), "len"); */
    if (dv.min_c == 0 && dv.x > 0)
    {
        /* do not touch  */
        if (dv.width < 0)
        {
            dv.width *= -1;
            ft_putnbr(dv.x);
            print_x_times(dv.width - ft_intlen(dv.x), ' ');
            return (0);
        }
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.min_c == 0 && dv.x < 0)
    {     
        /* do not touch  */
        if (dv.width < 0)
        {
            dv.width *= -1;
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
            return (0);
        }
        print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
        ft_putnbr_u(dv.x);
        return (0);
    }
    if (dv.min_c > 0 && dv.x < 0)
    {
        if (dv.width < 0)
        {
            dv.width *= -1;
            ft_putnbr_u(dv.x);
            print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
            return (0);
        }
        if (dv.min_c < ft_intlen(dv.x))
        {
            print_x_times(dv.width - ft_u_intlen(dv.x), ' ');
            print_x_times(dv.min_c - ft_u_intlen(dv.x * -1), '0');
            ft_putnbr_u(dv.x);
            return (0);
        }
        if (dv.width > dv.min_c && dv.min_c >= ft_u_intlen(dv.x))
            print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.min_c - ft_u_intlen(dv.x), '0');
        ft_putnbr_u(dv.x);
        return (0);
        /*  youarehere */
    }
    if (dv.min_c == 0 && dv.x == 0)
    {
        /* do not touch  */
        if (dv.width < 0)
        {
            dv.width *= -1;
            print_x_times(dv.width, ' ');
            return (0);
        }
        print_x_times(dv.width, ' ');
        return (0);
    }
    if (dv.x < 0 && dv.width < 0)
    {
        ft_putnbr(dv.x);
        dv.width *= -1;
        print_x_times(dv.width - ft_intlen(dv.x), ' ');
        return (0);
    }
    if (dv.x < 0)
    {
        print_x_times(dv.width - dv.min_c - 1, ' ');
        ft_putnbr(dv.x);
        print_x_times(ft_intlen(dv.x) - dv.width, '0');
        return (0);
    }
    if (dv.x == 0)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        ft_putnbr(dv.x);
        print_x_times(dv.min_c - 1, '0');
        return (0);
    }
    if (dv.min_c > 0 && dv.x > 0)
    {
        print_x_times(dv.width - dv.min_c, ' ');
        print_x_times(dv.width - dv.min_c - ft_intlen(dv.x) - 1, '0');
        ft_putnbr(dv.x);
        return (0);
    }
    print_x_times(dv.width - dv.min_c, ' ');
    ft_putnbr(dv.x);
    print_x_times(ft_intlen(dv.x) - dv.width, '0');
    return (0);
    return (0);
}

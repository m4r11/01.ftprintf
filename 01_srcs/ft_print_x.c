/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:56:36 by user              #+#    #+#             */
/*   Updated: 2021/04/09 13:58:39 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On this file: once a flag is found, is redirected through the array
** of function pointers ->here<- if 'x' || 'X' flag. 
** @25 treats padding on the left if width is >= 0
** @49 treats padding on the right if width is < 0
** @71 takes control after conv_xtoa || conv_Xtoa, to pipe down correct formating option
** @84 core drive for 'x' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
** @107 core drive for 'X' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
*/

#include "ft_printf.h"

int pad_right_x(t_dir_variables var)
{
    if (var.min_c == 0 && var.q != 0)
        return (ft_pad_right_x(var, (var.to_pad * -1) - ft_xlen(var.q), ' '));
    if (var.min_c == 0 && var.q == 0)
        return (print_x_times((var.to_pad * -1), ' '));
    if (var.min_c > 0 && var.q == 0)
        return (ft_pad_right_zero_x(var));
    if (var.min_c > 0 && var.q != 0)
        return (ft_pad_right_not_zero_x(var));
    if (var.min_c != -1 && var.min_c < ft_xlen(var.q))
        return (ft_pad_right_no_min_x(var));
    if (var.to_pad < 0 && var.min_c == -1 && var.q == 0)
        return (ft_pad_right_x(var, (var.to_pad * -1) - 1, ' '));
    ft_put_x_up(var.q, var.min_c, var.flag);
    if (ft_intlen(var.q) == 1)
        print_x_times((var.to_pad * -1) - 1, ' ');
    if (ft_intlen(var.q) == 2)
        print_x_times((var.to_pad * -1) - 2, ' ');
    else
        print_x_times((var.to_pad * -1) - ft_xlen(var.q), ' ');
    return (0);
}

int pad_left_x(t_dir_variables var)
{
    if (var.has_zero == 1)
        return (ft_has_zero_x(var));
    if (var.min_c == 0 && var.has_zero == -3)
        return (ft_no_minc_zero_x(var));
    if (var.min_c == -1 && var.has_zero == 1)
        return (ft_no_minc_no_zero_x(var));
    if (var.min_c == 0 && var.has_zero == 1)
        return (ft_no_minc_no_zero_x(var));
    if (var.to_pad > var.min_c && var.min_c > 0)
        return (ft_pad_left_big_pad(var));
    if (var.to_pad < var.min_c && var.min_c > 0)
        return (ft_pad_left_big_min(var));
    if (var.to_pad > 0 && var.min_c == -1 && var.q == 0)
        return (ft_pad_left_x(var, (var.to_pad - 1), ' '));
    if (var.to_pad > 0 && var.min_c == -1 && var.q != 0)
        print_x_times(var.min_c - var.to_pad, ' ');
    ft_put_x_up(var.q, var.min_c, var.flag);
    return (0);
}

int format_x(t_dir_variables var)
{
    if (var.to_pad > 0)
        return(pad_left_x(var));
    if (var.to_pad < 0)
        return (pad_right_x(var));
    if (var.to_pad == 0 && var.min_c == 0 && var.q != 0)
        ft_put_x_up(var.q, var.min_c, var.flag);
    if ((var.to_pad == 0 && var.min_c < 0) || var.min_c > 0)
        ft_put_x_up(var.q, var.min_c, var.flag);
    return (0);
}

int conv_xtoa(char *input, int index, int has_format, va_list args2)
{
    t_dir_variables var;

    var.has_zero = ft_zerochr(input, index);
    var.flag = 2;
    if (has_format == -1)
    {
        var.q = va_arg(args2, long);
        ft_put_x(var.q, var.flag);
        return (ft_intstrchr_flag(input, 'x', index));
    }
    else
    {
        var.to_pad = find_width(input, index, args2);
        var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        var.q = va_arg(args2, int);
        format_x(var);
        return (ft_intstrchr_flag(input, 'x', index));
    }
    return (FAIL);
}

int conv_Xtoa(char *input, int index, int has_format, va_list args2)
{
    t_dir_variables var;

    var.flag = 3;
    var.has_zero = ft_zerochr(input, index);
    if (has_format == -1)
    {
        var.q = va_arg(args2, long);
        ft_put_x(var.q, var.flag);
        return (ft_intstrchr_flag(input, 'X', index));
    }
    else
    {
        var.to_pad = find_width(input, index, args2);
        var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
        var.q = va_arg(args2, int);
        format_x(var);
        return (ft_intstrchr_flag(input, 'X', index));
    }
    return (FAIL);
}

/* handy & usefull copy paste costume debug:
debug_number(width, "w");
debug_number(min_c, "m");
 */
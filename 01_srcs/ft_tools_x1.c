/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_x1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:45:41 by user              #+#    #+#             */
/*   Updated: 2021/04/09 18:51:03 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_has_zero_x(t_dir_variables var)
{
    if (var.min_c == 0 && var.q == 0)
        return (print_x_times(var.to_pad - ft_intlen(var.q) + 1, ' '));
    if (var.min_c == -1 && var.q != 0)
    {
        if (var.min_c < ft_xlen(var.q))
            print_x_times(var.to_pad - ft_xlen(var.q), '0');
        if (var.min_c > ft_xlen(var.q))
            print_x_times(var.to_pad - var.min_c, '0');
        ft_put_x_up(var.q, var.min_c, var.flag);
        return (0);
    }
    if (var.min_c > 0 && var.q == 0)
        return (ft_pad_left_x(var, (var.to_pad - var.min_c), ' '));
    if (var.min_c > 0 && var.q != 0)
    {
        if (var.min_c < ft_xlen(var.q))
            return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
        if (var.min_c > ft_xlen(var.q))
            return (ft_pad_left_x(var, (var.to_pad - var.min_c), ' '));
    }
    if(var.q == 0)
        print_x_times(var.to_pad, '0');
    return (0);
}

int ft_no_minc_zero_x(t_dir_variables var)
{
    if (var.q == 0)
        return (print_x_times(var.to_pad, ' '));
    else
        return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
}

int ft_no_minc_no_zero_x(t_dir_variables var)
{
    if (var.q == 0)
        return (print_x_times((var.to_pad), ' '));
    else
        return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
}

int ft_no_minc_one_zero_x(t_dir_variables var)
{
    if (var.q == 0)
        return (print_x_times((var.to_pad), '0'));
    else
        return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), '0'));
}

int ft_pad_left_big_pad(t_dir_variables var)
{
    if (ft_xlen(var.q) == 1 && var.min_c > 1)
        return (ft_pad_left_x(var, (var.to_pad - var.min_c), ' '));
    if (var.q == 0)
        return (ft_pad_left_x(var, (var.to_pad - var.min_c), ' '));
    if (var.min_c < ft_xlen(var.q))
        return (ft_pad_left_x(var, (var.to_pad - ft_xlen(var.q)), ' '));
    else
        print_x_times(var.to_pad - var.min_c, ' ');
    ft_put_x_up(var.q, var.min_c, var.flag);
    return (0);
}
 

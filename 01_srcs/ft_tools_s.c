/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 16:52:17 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:03:47 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int put_string_pad_right(char *print, int to_pad)
{
    ft_putstr(print);
    print_x_times((to_pad * -1) - ft_strlen(print), ' ');
    return (0);
}

int put_string_pad_left(char *print, int to_pad)
{
    print_x_times((to_pad - ft_strlen(print)), ' ');
    ft_putstr(print);
    return (0);
}

int put_string_pad_left_limit(char *print, int to_pad, int min_c)
{
    print_x_times(to_pad - min_c, ' ');
    ft_putstr_limit(print, min_c);
    return (0);
}

int put_string_pad_right_limit(char *print, int to_pad, int min_c)
{
    ft_putstr_limit(print, min_c);
    print_x_times(to_pad - min_c, ' ');
    return (0);
}
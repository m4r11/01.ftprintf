/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_u_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 19:54:01 by user              #+#    #+#             */
/*   Updated: 2021/03/31 19:27:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h" 

char    put_spaces_before_u(int x, int converted)
{
    print_x_times(converted - 1, ' ');
    ft_putc(x);
    return(0);
}

char    put_spaces_afer_u(int x, int converted)
{
    ft_putnbr(x);
    print_x_times(converted - 1, ' ');
    return(0);
}
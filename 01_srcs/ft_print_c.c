/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:54:44 by user              #+#    #+#             */
/*   Updated: 2021/04/09 15:15:19 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On this file: once a flag is found, is redirected through the array
** of function pointers ->here<- if 'c' flag. 
** @24 treats padding on the left if width is >= 0
** @49 treats padding on the right if width is < 0
** @66 takes control after print_c, to pipe down correct formating option
** @79 core drive for 'c' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
*/

#include "ft_printf.h"

int	pad_left_c(int print, int to_pad, int min_c, int zero)
{
	if (zero == 1)
		return (ft_pad_left_printc_after_zero(print, to_pad));
	if (min_c == 0)
		return (ft_pad_left_printc_after(print, to_pad));
	if (min_c == 0 && zero == -1)
	{
		if (print == 0)
			return (print_x_times(to_pad, ' '));
		else
			 return (ft_pad_left_printc_after(print, to_pad));
	}
	if (to_pad > min_c)
	{
		if (min_c == -1)
			return (ft_pad_left_printc_after(print, to_pad));
		else
			return (ft_pad_left_printc_after(print, to_pad));
	}
	if (min_c > to_pad)
		to_pad = min_c;
	return (ft_pad_left_printc_after(print, to_pad));
}

int	pad_right_c(int print, int to_pad, int min_c)
{
	if (min_c == 0 && print != 0)
		return (ft_printc_pad_right(print, to_pad));
	if (min_c == 0 && print == 0)
		return (ft_printc_pad_right(print, to_pad));
	if (min_c == -1)
		 return (ft_printc_pad_right(print, to_pad * -1));
	if (min_c > 0 && print == 0)
		return (print_x_times(min_c, '0'));
	if (min_c < ft_xlen(print))
		return (ft_printc_pad_right(print, ((to_pad * -1) - ft_xlen(print))));
	ft_putc(print);
	print_x_times((to_pad * -1) - min_c, ' ');
	return (0);
}

int	format_c(int print, int to_pad, int min_c, int zero)
{
	if (to_pad > 0)
		return (pad_left_c(print, to_pad, min_c, zero));
	if (to_pad < 0)
		return (pad_right_c(print, to_pad, min_c));
	if (to_pad == 0 && min_c > 0)
		ft_putc(print);
	if (to_pad == 0 && min_c <= 0)
		ft_putc(print);
	return (0);
}

int	print_c(char *input, int index, int has_format, va_list args2)
{
	t_dir_variables	var;

	var.has_zero = ft_intstrchr(input, '0', index);
	if (has_format == -1)
	{
		var.q = va_arg(args2, int);
		ft_putc(var.q);
		return (ft_intstrchr_flag(input, 'c', index));
	}
	else
	{
		var.to_pad = find_width_c(input, index, args2);
		var.min = find_precision(input, ft_intstrchr(input, '.', index), args2);
		var.q = va_arg(args2, int);
		format_c(var.q, var.to_pad, var.min, var.has_zero);
		return (ft_intstrchr_flag(input, 'c', index));
	}
	return (FAIL);
}

/* handy & usefull copy paste costume debug:
debug_number(width, "w");
debug_number(min_c, "m");
 */
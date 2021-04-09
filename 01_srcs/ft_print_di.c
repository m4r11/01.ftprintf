/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:49:12 by user              #+#    #+#             */
/*   Updated: 2021/04/09 15:21:51 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On this file: once a flag is found, is redirected through the array
** of function pointers ->here<- if 'd' || 'i' flag. 
** @24 treats padding on the left if width is >= 0
** @52 treats padding on the right if width is < 0
** @79 takes control after print_c, to pipe down correct formating option
** @92 core drive for 'i' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
** @120 core drive for 'd' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
*/

#include "ft_printf.h"

int pad_left_ints(int print, int to_pad, int min_c, int zero)
{
	if  (min_c == 0 && print != 0)
		return (ft_pad_left_putnbr(print, to_pad, min_c));
	if  (min_c == 0 && print == 0)
		return (print_x_times(to_pad, ' '));
	if (min_c == -1 && zero == -3)
		return (ft_pad_left_no_min_no_zero( print, to_pad, min_c));
	if (min_c == -1 && zero == 1)
		return(ft_pad_left_no_min_zero(print, to_pad, min_c));
	if (zero == 1)
		return (ft_pad_left_putnbr_zero(print, to_pad, min_c));
	if (to_pad <= min_c)
	{
		ft_putnbr_up(print, min_c);
		return (0);
	}
	if (min_c < to_pad && min_c > 0)
		return (ft_pad_left_minor_min(print, to_pad, min_c));
	if (min_c == 0 && print == 0)
		return (print_x_times(to_pad, ' '));
	if (to_pad > min_c)
		return (ft_pad_left_bigger_pad(print, to_pad, min_c));
	if (min_c > to_pad)
		to_pad = min_c;
	return (ft_pad_left_putnbr_min(print, to_pad, min_c));
}

int pad_right_ints(int print, int to_pad, int min_c, int zero)
{
	if (min_c == 0 && print != 0)
		return (ft_pad_right(print, to_pad, min_c));
	if (min_c == -1 && print == 0)
	{
		if (zero != -1 && print < 0)
		{
			min_c = to_pad;
			ft_putnbr_up(print, min_c);
			return (0);
		}
		ft_putnbr_up(print, min_c);
		print_x_times((to_pad * -1) - 1, ' ');
		return (0);
	}
	if (min_c == 0 && print == 0)
		return (print_x_times((to_pad * -1), ' '));
	if (min_c < ft_intlen(print))
		 return (ft_pad_right(print, to_pad, min_c));
	ft_putnbr_up(print, min_c);
	if (print < 0)
		return (print_x_times((to_pad * -1) - min_c - 1, ' '));
	else
		return (print_x_times((to_pad * -1) - min_c, ' '));
}

int format_ints(int print, int to_pad, int min_c, int zero)
{
	if (to_pad > 0)
		return (pad_left_ints(print, to_pad, min_c, zero));
	if (to_pad <= 0)
		return (pad_right_ints(print, to_pad, min_c, zero));
	if (to_pad == 0 && min_c > 0)
		ft_putnbr_up(print, min_c);
	if (to_pad == 0 && min_c == 0)
		ft_putnbr_up(print, min_c);
	return (0);
}

int conv_itoa(char *input, int index, int has_format, va_list args2)
{
	signed int x;
	t_dir_variables	var;

	var.to_pad = 0;
	if (has_format == -1)
	{
		x = va_arg(args2, signed int);
		ft_putnbr(x);
		return (ft_intstrchr_flag(input, 'i', index));
	}
	else
	{
		var.to_pad = find_width_d(input, index, args2);
		var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
		var.has_zero = ft_zerochr(input, index);
		if(input[index +1] == ' ')
			ft_putc(' ');
		x = va_arg(args2, int);
		format_ints(x, var.to_pad, var.min_c, var.has_zero);
		return (ft_intstrchr_flag(input, 'i', index));
	}
	return (FAIL);
}

int conv_dtoa(char *input, int index, int has_format, va_list args2)
{
	signed int x;
	t_dir_variables	var;

	if (has_format == -1)
	{
		x = va_arg(args2, signed int);
		ft_putnbr(x);
		return (ft_intstrchr_flag(input, 'd', index));
	}
	else
	{
		var.to_pad = find_width_d(input, index, args2);
		var.min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
		var.has_zero = ft_zerochr(input, index);
		x = va_arg(args2, int);
		format_ints(x, var.to_pad,var.min_c, var.has_zero);
		return (ft_intstrchr_flag(input, 'd', index));
	}
	return (FAIL);
}

void ft_putnbr_up(int print, int min_c)
{
	int len;
	char *intmin;

	if (print <= INT_MAX && print >= INT_MIN)
	{
		if (print < 0)
		{
			print *= -1;
			ft_putc('-');
		}
		if (print == INT_MIN)
		{
			intmin = "2147483648";
			ft_putstr(intmin);
			if (min_c > 0)
				print_x_times(min_c - ft_strlen(intmin), '0');
			return;
		}
		len = ft_intlen(print);
		if (min_c > 0 && print == 0)
		{
			print_x_times(min_c, '0');
			return;
		}
		if (min_c > 0 && print != 0)
		{
			if (ft_intlen(print) == 1)
				print_x_times(min_c - 1, '0');
			else
				print_x_times(min_c - len, '0');
		}
		if (print > 9)
		{
			ft_putnbr(print / 10);
			ft_putnbr(print % 10);
		}
		else
			ft_putc(print + '0');
	}
	return;
}

/* handy & usefull copy paste costume debug:
debug_number(width, "w");
debug_number(min_c, "m");
 */
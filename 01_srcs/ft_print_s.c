/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 08:18:21 by user              #+#    #+#             */
/*   Updated: 2021/04/08 15:01:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*On this file: once a flag is found, is redirected through the array
** of function pointers ->here<- if 's' flag. 
** @21 treats NULL string.
** @48 treats padding on the left if width is >= 0
** @72 treats padding on the right if width is < 0
** @90 takes control after print_str, to pipe down correct formating option
** @112 core drive for 's' flag. this i sthe first function to receive operative
** control after parse function in printf.c call the get_converter[func array]
*/

#include "ft_printf.h"

int	null_string(char *print, int to_pad, int min_c, int zero)
{
	print = "(null)";
	if (to_pad == 0 && min_c > 0 && min_c <= ft_strlen(print))
		return (ft_putstr_limit(print, min_c));
	if (to_pad <= 0 && min_c > 0 && min_c <= ft_strlen(print))
		return (put_string_pad_right_limit(print, (to_pad * -1), min_c));
	if (to_pad > 0 && min_c > 0 && min_c <= ft_strlen(print))
		return (put_string_pad_left_limit(print, to_pad, min_c));
	if (min_c == 0 && to_pad < 0)
		return (print_x_times((to_pad * -1), ' '));
	if (min_c == 0 && to_pad > 0)
		return (print_x_times(to_pad, ' '));
	if (min_c == -1 && to_pad > 0)
		return (put_string_pad_left(print, to_pad));
	if (min_c == -1 && to_pad < 0)
		return (put_string_pad_right(print, to_pad));
	if (min_c > ft_strlen(print) && to_pad <= 0)
		return (put_string_pad_right(print, to_pad));
	if (min_c > ft_strlen(print) && to_pad > 0)
		return (put_string_pad_left(print, to_pad));
	else
		ft_putstr(print);
	return (0);
}

int	pad_left_s(char *print, int to_pad, int min_c, int zero)
{
	if (min_c == 0)
		return (print_x_times(to_pad, ' '));
	if (to_pad > min_c && min_c > 0)
	{
		if (min_c > ft_strlen(print))
			return (put_string_pad_left(print, to_pad));
		else
			return (put_string_pad_left_limit(print, to_pad, min_c));
	}
	if (min_c == -1)
		return (put_string_pad_left(print, to_pad));
	if (min_c > ft_strlen(print))
		return (put_string_pad_left(print, to_pad));
	print_x_times(to_pad - min_c, ' ');
	if (min_c > 0)
		ft_putstr_limit(print, min_c);
	else
		ft_putstr(print);
	return (0);
}

int	pad_right_s(char *print, int to_pad, int min_c, int zero)
{
	if (to_pad < 0 && min_c == -1)
	{
		if (ft_strlen(print) < (to_pad * -1))
			return (put_string_pad_right(print, to_pad));
		else
			return (put_string_pad_right(print, to_pad));
	}
	if (to_pad < 0 && min_c > 0 && min_c <= ft_strlen(print))
		return(put_string_pad_right_limit(print, (to_pad * -1),min_c));
	if (min_c == 0 && zero == -3)
		return(print_x_times((to_pad * -1) - min_c, ' '));
	ft_putstr(print);
	print_x_times((to_pad * -1) - ft_strlen(print), ' ');
	return (0);
}

int	format_string(char *print, int to_pad, int min_c, int zero)
{
	if (print == NULL)
		return (null_string(print, to_pad, min_c, zero));
	if (to_pad > 0)
		return (pad_left_s(print, to_pad, min_c, zero));
	if (to_pad < 0)
		return (pad_right_s(print, to_pad, min_c, zero));
	if (to_pad == 0 && min_c == 0)
		return (0);
	if (to_pad == 0 && min_c < 0)
	{
		 ft_putstr(print);
		return (0);
	}
	if (to_pad == 0 && min_c <= ft_strlen(print))
		return (ft_putstr_limit(print, min_c));
	if (to_pad == 0 && min_c > 0)
		ft_putstr(print);
	else
		ft_putstr_limit(print, min_c);
	print_x_times((to_pad * -1) - ft_strlen(print), ' ');
	return (0);
}

int	print_str(char *input, int index, int has_format, va_list args2)
{
	char	*print;
	int		width;
	int		min_c;
	int		zero;
	
	zero = ft_intstrchr(input, '0', index);
	if (has_format == -1)
	{
		if (!(print = va_arg(args2, char *)))
			print = "(null)";
		ft_putstr(print);
		return (ft_intstrchr_flag(input, 's', index));
	}
	else
	{
		width = find_width_c(input, index, args2);
		min_c = find_precision(input, ft_intstrchr(input, '.', index), args2);
		print = va_arg(args2, char *);
		format_string(print, width, min_c, zero);
		return (ft_intstrchr_flag(input, 's', index));
	}
	return (FAIL);
}

/* handy & usefull copy paste costume debug:
debug_number(width, "w");
debug_number(min_c, "m");
 */
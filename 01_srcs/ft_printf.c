/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:45:44 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On this file: main engine for my 
** printf implementation.
** @24 array of fruntion pointers to 
** re-direct the matched flag to it's
** correspondant function.
** @45 print_string aux function: 
** print the formatting string until a '%'.
** @58 ft_printf: prints until '%', index is 
** stored localy and sent to parse funtion to 
** match a flag, if there is one. keeps on 
** looping until end of string.
** @75 parse function: find_flags has 
** the value of the flag, find_dir has value of -1 
** if no formatting is found. It's part of the first exit plan 
** for ft_printf having in mind efficiency. 
** The index has now the value of the flag. 
** each converting funtin will return the position of the flag
** plus 1, to make ir easy for the loop to continue without resetting. 
** @89 get_converter is a typedef function for the func*, 
** it takes the find_flag int, and matches it
** with the right function. 
*/

#include "ft_printf.h"

static fptrconv		g_converter [] = 
	{
		&conv_dtoa,
		&conv_itoa,
		&conv_xtoa,
		&conv_Xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&conv_fetoa,
		&print_str,
		&print_str,
		&print_c,
		&conv_fetoa,
		&conv_otoa,
		&print_ptr,
		&print_n,
		&print_percent,
};

int	print_string(char *s, int c, int start)
{
	while (s[start] != c && s[start] != '\0')
	{
		ft_putc(s[start]);
		start++;
	}
	if (s[start] == c)
		return (start);
	else
		return (END);
}

int	ft_printf(const char *format, ...)
{
	t_struct	v;
	int			i;

	va_start(args, format);
	va_copy(args2, args);
	i = 0;
	v.temp = ft_strdup(format);
	while (i != END)
		i = parse(v.temp, print_string(v.temp, '%', i));
	va_end(args);
	free(v.temp);
	return (counter(0));
}

int	parse(char *to_parse, int i)
{
	int	find_dir;
	int	find_flag;

	if (i == END)
		return (END);
	find_flag = loop_through(CONV_S, to_parse, i);
	find_dir = loop_for_directives(to_parse, i);
	i = g_converter[find_flag](to_parse, i, find_dir, args2) + 1;
	if (i == END_STRING || i == END)
		return (END);
	else
		return (i);
}

/* 
 string to fetch types
** CONV_S "dixXufeEsScgopn%"
** string to fetch dir
** DIR_S "*-+ 0hljz.#123456789" 
*/

/* handy & usefull copy paste costume debug:
debug_number(width, "w");
debug_number(min_c, "m");
 */
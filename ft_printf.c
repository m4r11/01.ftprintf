/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/06 17:12:15 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static fptr get_converter[] =
	{

		&conv_itoa,
		&conv_itoa,
		&conv_ftoa,
		&conv_xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&conv_dtoa,
		&print_str,
		&print_str,
};

int ft_printf(char *format, ...)
{
	va_list args;
	va_list args2;
	t_struct v;
	type_f t_f;
	t_type type;

	va_start(args, format);
	va_copy(args2, args);

	v.i = 0;
	v.f = format;
	t_f = d;
	while (v.f[v.i])
	{
		if (v.f[v.i] != '%')
			ft_putc(v.f[v.i]);
		else
		{
			v.i++;
			v.j = 0;
			while (CONV_S[v.j++])
			{
				if (CONV_S[v.j] == v.f[v.i])
					get_converter[v.j](type, args2);
			}
		}
		v.i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_putstr("%S FLAG\n");
	ft_printf("HELLO say %s to %s because she is %s \n", "hello", "catarina", "pretty");
	printf("HELLO say %s to %s because she is %s \n", "hello", "catarina", "pretty");
	ft_putstr("%d FLAG\n");
	ft_printf("%i %i %i\n", 3, 666, 9);
	printf("%d %d %d", 3, 666, 9);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/02 18:41:01 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	char *t;
	char *next;
	va_list args;
	va_list args2;
	va_start(args, format);
	va_copy(args2, args);
	size_t i;
	type_f;

	i = 0;
	t = format;
	type_f = d;
	while (t[i])
	{
		if (t[i] != '%')
		{
			ft_putc(t[i]);
		}
		else
		{
			while (t[i] && type_f <= n)
			{
				i++;
				if (t[i] == type_f)
				{
					next = va_arg(args2, char *);
					ft_putstr(next);
				}
			}
			
		}

		i++;
	}
	va_end(args);
	return (0);

	return (0);
}

int main()
{
	ft_printf("i want to say %s to %s", "hello", "catarina");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:24 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/09 18:15:49 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putc(char c)
{
	write(1, &c, 1);
	counter(1);
}

void ft_putstr(char *str)
{
	t_struct v;
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		ft_putc(str[i]);
		++i;
		//counter(1);
	}
}

int ft_strlen(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		++x;
	}
	return (x);
}

/* int ft_arglen(va_list TYPE)
{
	int i;
	static int x;
	if (!TYPE)
		return (x += 0);
	i = 0;
	while(&TYPE[i])
	{
		i++;
		x++;
	}
	debug_number(i,"i");
	debug_number(x, "x");
	return (x += i);
	return (0);
} */

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

int ft_intlen_bonus(int n)
{
	int len;
	len = 1;
	while (n > 9)
	{
		len++;
		n /=10;
	}
	return (len);
}

int ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power != 0)
	{
		result = nb * ft_recursive_power(nb, power - 1);
	}
	return (result);
}

char *ft_strdup(const char *s1)
{
	char *s2;
	size_t i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

int counter(int n)
{
	static int res = 0;

	res += n;
	return(res);
}
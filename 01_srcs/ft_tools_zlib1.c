/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zlib1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:24 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:31:40 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *str)
{
	if (!str)
		return(0);
	int x;
	x = 0;
	while (str[x] != '\0')
	{
		++x;
	}
	return (x);
}

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

int ft_intlen(int n)
{
	int len;
	len = 1;
	if (n < 0)
	{
		len = 2;
		n *= -1;
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return(len);
	}
	else 
	{
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return (len);
	}
	return(-1);
}

int ft_u_intlen(unsigned int n)
{
	int len;
	len = 1;
	if (n < 0)
	{
		len = 2;
		n *= -1;
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return(len);
	}
	else 
	{
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return (len);
	}
	return(-1);
}


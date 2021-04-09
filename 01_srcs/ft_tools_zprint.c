/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:39:56 by user              #+#    #+#             */
/*   Updated: 2021/04/09 14:31:33 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putc(char c)
{
	write(1, &c, 1);
	counter(1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		ft_putc(str[i]);
		++i;
	}
}

char    ft_putstr_limit(char *str, int limit)
{
	int i;
	i = 0;
	while (i < limit)
	{
		ft_putc(str[i]);
		i++;
	}
	return(0);
}

char	print_x_times(int n, char c)
{
	if (n == 0)
		return(0);
	while (n > 0)
	{
		ft_putc(c);
		n--;
	}
	return(0);
}

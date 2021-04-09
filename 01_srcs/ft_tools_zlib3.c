/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zlib3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:26:30 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:31:46 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ratoi(const char *str, int i)
{
	if (!*str || *str > '9' || *str < '0')
		return (i);
	i = i * 10 + (*str - '0');
	return (ft_ratoi(++str, i));
}

int			ft_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		return (-ft_ratoi(++str, 0));
	if (*str == '+')
		return (ft_ratoi(++str, 0));
	return (ft_ratoi(str, 0));
}

int			ft_simple_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == '-')
		str++;
	return (ft_ratoi(str, 0));
}

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

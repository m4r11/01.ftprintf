/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zlib2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:24:40 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:31:52 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	static int res;

	res += n;
	return(res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

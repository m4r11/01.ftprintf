/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:57:20 by user              #+#    #+#             */
/*   Updated: 2021/03/23 14:21:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static int	ft_ratoi(const char *str, int i)
{
	if (!*str || *str > '9' || *str < '0')
		return (i);
	i = i * 10 + (*str - '0');
	return (ft_ratoi(++str, i));
}

int			ft_simple_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == '-')
		str++;
	return (ft_ratoi(str, 0));
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}



int     find_width(char *dir, int start)
{
    int width;

    if (dir[start + 1] == '-')
       return(width = (ft_simple_atoi(&dir[start+2]) * -1));
    if (ft_isdigit(dir[start + 1]) == 1)
        return(width = ft_simple_atoi(&dir[start+1]));
    return(0);
}

int         main()
{
    char *dir = " %-3.2i \n";
    char *dir1 = " %-3.2i \n";
    char *dir2 = " %-10.42i ";
    int width;
    int width1;
    int width2;
    
    width = find_width(dir, 1);
    width1 = find_width(dir1, 1);
    width2 = find_width(dir2, 1);
    printf("%d\n", width);
    printf("%d\n", width1);
    printf("%d\n", width2);
return(0);
}
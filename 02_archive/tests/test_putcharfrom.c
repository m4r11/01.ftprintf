/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putcharfrom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:19:47 by user              #+#    #+#             */
/*   Updated: 2021/03/25 10:43:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

# define DIR_S "*-+ 0hljz.#123456789"
# define CONV_S "dixXufeEsScgopn"
# define END -3

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

int		ft_putcharfrom(char *s, int start, char flag)
{
	int i;
	i = start;
    int len = 0;
    while(s[i] != CONV_S[flag])
        i++;
    if (i == (ft_strlen(s)-1))
        return(END);
    return(i + 1);
}

int main()
{
    //char *s = " *%-*.*i* *%*.*i* ";
    char *s = "%c";
    char *s2 = " %c ";
    int from;
    int from2;
    char flag = 10;
    from = ft_putcharfrom(s, 0, flag);
    from2 = ft_putcharfrom(s2, 1, flag);
    printf("%d\n", from);
    printf("%d\n", from2);
    printf("%d\n", ft_strlen(s));
    printf("%d\n", ft_strlen(s2));
    printf("%c\n", CONV_S[flag]);
}
/* 
** todo: rewrite this func with (DIR[flag]) to work for every case
*/
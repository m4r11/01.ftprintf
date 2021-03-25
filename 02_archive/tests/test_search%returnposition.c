/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_search%returnposition.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:11:47 by user              #+#    #+#             */
/*   Updated: 2021/03/24 19:19:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_intstrchr(char *s, int c, int start)
{
	int i;
	i = start;
	if (s[start] == c)
		i++;
	while(s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return(i);
	return(-1);
}

int     main()
{
    int r, r2, r3;
    char *s, *s2, *s3;
    s = " %c ";
    s2 = "%c%*c";
    s3 = "%s hello this is a test %d";

    r = ft_intstrchr(s, '%', 1);
    r2 = ft_intstrchr(s2, '%', 0);
    r3 = ft_intstrchr(s3, '%', 0);

    printf("%d\n%d\n%d\n", r, r2, r3);
}
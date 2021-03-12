/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_index_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:42:23 by user              #+#    #+#             */
/*   Updated: 2021/03/11 22:54:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* int  get_index(char *s1, char *s2)
{
    int i = -1;
    int j = 0;
    while(s1[i] != '\0')
    {
        i++;
        j = 0;
        if (s2[j] == s1[i])
            return(i);
                break;
        if (s1[i] != s2[j])
            j++;
    }
    return(i);
} */

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


int  get_index(char *s1, char *s2)
{
    int len1;
    int len2;
    int j;
    int i;
 
 printf("%s", s1);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
   printf("%d", len1);
   printf("%d", len2);
   if (!s1 || !s2)
        return(0);
    while(s1[i] <= len1)
    {
        printf("%d", i);
        while(s2[j]<=len2)
        {
            if (s1[i] == s2[j])
            {
                return(i);
                break;
            }
            j++;
            printf("%d",j);
        }
        i++;
        j=0;       
    }
    return(-1);  
}


int  main()
{
    char *s1 = "-+ 0hljz.#123456789";
    char *s2 = "%-hs\n";
    int r;

    r = get_index(s1, s2);
    printf("the index is %d", r);
}
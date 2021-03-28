/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:43:24 by user              #+#    #+#             */
/*   Updated: 2021/03/28 13:10:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_first_flag(char *input)
{
    int i;
    int j;
    int flag1_end;
    int percent1;
    int percent2;

    percent1 = ft_intstrchr_flag(input, '%', 0);
    percent2 =  ft_intstrchr(input, '%', percent1);
    flag1_end = percent2;
    while(input[flag1_end])
    {
        i = 0;
        while (CONV_S[i])
        {
             if(CONV_S[i] == input[flag1_end])
             {
                 j = 0;
                 while(DIR2_S[j])
                 {
                     if ((DIR2_S[j] == input[flag1_end-1]) || '%' == input[flag1_end-1])
                     {
                        return(flag1_end + 1);
                     }
                    j++;
                 }
             }
            i++;
            //debug_number(i, "i");
        }
        //printf("this is the end:%d\n", flag1_end);
        flag1_end--;
    }
    return(0);
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

int		ft_intstrchr_flag(char *s, int c, int start)
{
	int i;
	i = start;
	while(s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return(i);
	return(-1);
}

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

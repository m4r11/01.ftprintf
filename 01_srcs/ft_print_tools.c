/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:39:56 by user              #+#    #+#             */
/*   Updated: 2021/03/28 14:14:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char ft_putstr_limit(char *str, int limit)
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

int		ft_putcharfrom(char *s, int start, char flag)
{
	int i;
	i = start;
    int len = 0;
    while(s[i] != CONV_S[flag])
        i++;
    if (i == (ft_strlen(s)-1))
        return(END);
    return(i);
}

int   print_the_middle(char *input, int flag1_end)
{
    int start;
    int middle;
    int end;

    start = ft_intstrchr_flag(input, '%', 0);
    //printf("start : %d\n" ,start);
    end = ft_intstrchr(input, '%', start);
    //printf("end : %d\n", end);
   // printf("flag1end : %d\n", flag1_end);
    middle = flag1_end;
    //printf("middle : %d\n", middle);
    if (middle == 0)
        return(0);
    while(input[middle] != input[end])
    {
            ft_putc(input[middle]);
            middle++;
    }
    //debug_number(middle, "middle");
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
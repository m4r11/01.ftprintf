/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zsearch2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:27:36 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 14:31:03 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_intstrchr_flag(char *s, int c, int start)
{
    int i;
    i = start;
    while (s[i] != '\0' && s[i] != c)
        i++;
    if (c == s[i])
        return (i);
    return (END);
}

int ft_intstrchr(char *s, int c, int start)
{
    int i;
    i = start;
    if (s[start] == c)
        i++;
    while (s[i] != '\0' && s[i] != c)
        i++;
    if (c == s[i])
        return (i);
    return (END);
}

int ft_zerochr(char *s, int start)
{
    if (s[start + 1] == '0')
        return (1);
    else
        return (END);
}

int get_index(char *s1, char *s2)
{
    int j;
    int mini_index = INT_MAX;
    int len1 = ft_strlen(s1);
    char *start = ft_strchr(s2, '%');
    //debug_str(start, "start");
    int len2 = ft_strlen(start);
    //debug_number(len1, "len1");
    int i = 0;
    while (i < len2)
    {
        i++;
        j = 0;
        while (j < len1)
        {
            j++;
            if (s2[i] == s1[j] && j < mini_index)
            {
                mini_index = j;
                return (j);
                break;
            }
        }
    }
    if (mini_index != j)
        return (NO_FORMAT);
    return (0);
}

int find_precision(char *dir, int start, va_list args2)
{
    int format;
    if (start == -1)
        return (-1);
    if (dir[start] == '.' && dir[start + 1] != '*')
        return (format = (ft_simple_atoi(&dir[start + 1])));
    if (dir[start] == '*' || dir[start + 1] == '*')
        return (format = va_arg(args2, int));
    return (-1);
}
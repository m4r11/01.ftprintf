/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:43:24 by user              #+#    #+#             */
/*   Updated: 2021/04/06 10:57:12 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00_includes/ft_printf.h"

int find_first_flag(char *input)
{
    int i;
    int j;
    int flag1_end;
    int percent1;
    int percent2;
    static int pin;

    percent1 = ft_intstrchr_flag(input, '%', pin);
    percent2 = ft_intstrchr(input, '%', percent1);
    flag1_end = percent2;
    while (input[flag1_end])
    {
        i = 0;
        while (CONV_S[i])
        {
            if (CONV_S[i] == input[flag1_end])
            {
                j = 0;
                while (DIR2_S[j])
                {
                    if ((DIR2_S[j] == input[flag1_end - 1]) || '%' == input[flag1_end - 1])
                    {
                        return (flag1_end + 1);
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
    pin = percent1;
    return (END);
}

int find_width(char *dir, int start, va_list args2)
{
    int width;
    if (start == -1)
        return (0);
    width = 0;
    while (dir[start++] != '.')
    {
 //debug_str(&dir[start], "width");
        if (dir[start] == '0')
            start += 1;
        if (dir[start] == '-' && dir[start + 1] != '*')
        {
            if (dir[start + 1] != '0')
                return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
        }
        if (dir[start] == '*')
        {
            if ((dir[start - 1] == '%') || (dir[start - 2] == '%' && dir[start - 1] == '-') || dir[start - 3] == '%')
            {
                width = va_arg(args2, int);
                if (width > 0)
                    return(-1 * width);
                else
                    return(width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
            return (width = ft_simple_atoi(&dir[start]));
    }
    return(0);
}

int find_width_c(char *dir, int start, va_list args2)
{
    int width;
    if (start == -1)
        return (0);
    width = 0;
    while (dir[start++] != '.')
    {
 //debug_str(&dir[start], "width");
        if (dir[start] == '0')
            start += 1;
        if (dir[start] == '-' && dir[start + 1] != '*')
        {
            if (dir[start + 1] != '0')
                return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
        }
        if (dir[start] == '*')
        {
            if  ((dir[start - 2] == '%' && dir[start - 1] == '-') || (dir[start - 3] == '%' && dir[start - 2] == '-'))
            {
                width = va_arg(args2, int);
                if (width > 0)
                    return(-1 * width);
                else
                    return(width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
            return (width = ft_simple_atoi(&dir[start]));
    }
    return(0);
}

int find_width_p(char *dir, int start, va_list args2)
{
    int width;
    if (start == -1)
        return (0);
    width = 0;
    while (dir[start++] != '.')
    {
    //debug_str(&dir[start], "width");
        if (dir[start] == '0')
            start += 1;
        if (dir[start] == '-' && dir[start + 1] != '*')
        {
            if (dir[start + 1] != '0')
                return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
        }
        if (dir[start] == '*')
        {
            if  ((dir[start - 2] == '%' && dir[start - 1] == '-') || (dir[start - 3] == '%' && dir[start - 2] == '-'))
            {
                width = va_arg(args2, int);
                if (width > 0)
                    return(-1 * width);
                else
                    return(width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
            return (width = ft_simple_atoi(&dir[start]));
    }
    return(0);
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
    if(s[start + 1] == '0')
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
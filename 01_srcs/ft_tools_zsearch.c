/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_zsearch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:43:24 by user              #+#    #+#             */
/*   Updated: 2021/04/09 14:30:34 by mvaldeta         ###   ########.fr       */
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

int find_width_d(char *dir, int start, va_list args2)
{
    int width;
    if (start == -1)
        return (0);
    width = 0;
    while ((dir[start++] && dir[start] != '.' ) && dir[start] != '\0')
    {
        if (dir[start] == '0')
            start += 1;
        if (dir[start] == '-' && dir[start + 1] != '*')
        {
            if (dir[start + 1] != '0')
                return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
        }
        if (dir[start] == '*')
        {
            if (((dir[start - 2] == '%' && dir[start - 1] == '-') ||
             (dir[start - 3] == '%' && dir[start - 2] == '-') ||
             dir[start - 1] == '-'))
            {

                width = va_arg(args2, int);
                if (width > 0)
                    return (-1 * width);
                else
                    return (width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
        {
            if (dir[start - 2] == '-')
                return (width = ft_simple_atoi(&dir[start]) * -1);
            else
                return (width = ft_simple_atoi(&dir[start]));
        }
    }
    
    return (0);
}

int find_width(char *dir, int start, va_list args2)
{
    int width;
    if (start == -1)
        return (0);
    width = 0;
    while (dir[start++] != '.')
    {
        if (dir[start] == '0')
            start += 1;
        if (dir[start] == '-' && dir[start + 1] != '*')
        {
            if (dir[start + 1] != '0')
                return (width = (ft_simple_atoi(&dir[start + 1]) * -1));
        }
        if (dir[start] == '*')
        {
            if (((dir[start - 2] == '%' && dir[start - 1] == '-') ||
             (dir[start - 3] == '%' && dir[start - 2] == '-') ||
             dir[start - 1] == '-'))
            {

                width = va_arg(args2, int);
                if (width > 0)
                    return (-1 * width);
                else
                    return (width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
        {
            if (dir[start - 2] == '-')
                return (width = ft_simple_atoi(&dir[start]) * -1);
            else
                return (width = ft_simple_atoi(&dir[start]));
        }
    }
    return (0);
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
            if ((dir[start - 2] == '%' && dir[start - 1] == '-') || (dir[start - 3] == '%' && dir[start - 2] == '-'))
            {
                width = va_arg(args2, int);
                if (width > 0)
                    return (-1 * width);
                else
                    return (width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
        {
            if (dir[start - 2] == '-')
                return (width = ft_simple_atoi(&dir[start]) * -1);
            else
                return (width = ft_simple_atoi(&dir[start]));
        }
    }
    return (0);
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
            if ((dir[start - 2] == '%' && dir[start - 1] == '-') || (dir[start - 3] == '%' && dir[start - 2] == '-'))
            {
                width = va_arg(args2, int);
                if (width > 0)
                    return (-1 * width);
                else
                    return (width);
            }
            else
                return (width = va_arg(args2, int));
        }
        if (ft_isdigit(dir[start]) == 1 && &dir[start] != 0)
            return (width = ft_simple_atoi(&dir[start]));
    }
    return (0);
}


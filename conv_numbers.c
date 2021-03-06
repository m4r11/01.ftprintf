/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:01:13 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/06 17:16:03 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool is_base_valid(char *str)
{
    char *curr;
    int index;
    int jndex;

    curr = str;
    if (str == 0 || ft_strlen(str) <= 1)
        return (false);
    while (*curr)
    {
        if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f' || *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
            return (false);
        curr++;
    }
    index = 0;
    while (index < curr - str)
    {
        jndex = index + 1;
        while (jndex < curr - str)
            if (str[index] == str[jndex++])
                return (false);
        index++;
    }
    return (true);
}

void ft_putnbr_base_recursiva(int number, char *base, int baseleng)
{
    if (number == -2147483648)
    {
        ft_putnbr_base_recursiva(number / baseleng, base, baseleng);
        write(1, &(base[-(number % baseleng)]), 1);
        return;
    }
    if (number < 0)
    {
        write(1, "-", 1);
        ft_putnbr_base_recursiva(-number, base, baseleng);
        return;
    }
    if (number > baseleng - 1)
        ft_putnbr_base_recursiva(number / baseleng, base, baseleng);
    write(1, &(base[number % baseleng]), 1);
}

void ft_putnbr_base(int nbr, char *base)
{
    int baseleng;

    if (!is_base_valid(base))
        return;
    baseleng = ft_strlen(base);
    ft_putnbr_base_recursiva(nbr, base, baseleng);
}
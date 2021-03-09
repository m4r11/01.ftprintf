/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:01:13 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/08 22:25:30 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr(int nb)
{
    if (nb <= INT_MAX && nb >= INT_MIN)
    {
        if (nb == INT_MIN)
        {
            ft_putc('-');
            ft_putc('2');
            ft_putnbr(147483648);
        }
        else if (nb < 0)
        {
            ft_putc('-');
            ft_putnbr(-nb);
        }
        else if (nb > 9)
        {
            ft_putnbr(nb / 10);
            ft_putnbr(nb % 10);
        }
        else
            ft_putc(nb + '0');
    }
}

void ft_putnbr_rebase(int number, int baselen)
{
    if (number == -2147483648)
    {
        ft_putnbr_rebase(number / baselen, baselen);
        ft_putnbr(number % baselen);
        return;
    }
    if (number < 10)
    {
        ft_putnbr(number % baselen);
    }
    if (number > baselen - 1)
        ft_putnbr(number % baselen);
}

void ft_putnbr_base(int nbr, char *base)
{
    int baselen;

    baselen = ft_strlen(base);
    ft_putnbr_rebase(nbr, baselen);
}

char *ft_itoa(int n)
{
    char *str;
    long nbr;
    size_t size;

    nbr = n;
    size = n > 0 ? 0 : 1;
    nbr = nbr > 0 ? nbr : -nbr;
    while (n)
    {
        n /= 10;
        size++;
    }
    if (!(str = (char *)malloc(size + 1)))
        return (0);
    *(str + size--) = '\0';
    while (nbr > 0)
    {
        *(str + size--) = nbr % 10 + '0';
        nbr /= 10;
    }
    if (size == 0 && str[1] == '\0')
        *(str + size) = '0';
    else if (size == 0 && str[1] != '\0')
        *(str + size) = '-';
    return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_n_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:01:13 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/01 17:37:40 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putnbr(int nb)
{
    //debug_number(nb, "nb");
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
    return;
}

void ft_putnbr_u(unsigned int nb)
{
    if (nb <= UINT_MAX)
    {
        if (nb == UINT_MAX)
        {
            ft_putc('4');
            ft_putc('2');
            ft_putnbr(94967295);
            return ;
        }
/*         if (nb == 101)
        {
            ft_putc('4');
            ft_putc('2');
            ft_putnbr_u(94967295);
            return;
        } */
        else if (nb < 0)
        {
            ft_putc('-');
            ft_putnbr_u(-nb);
        }
        else if (nb > 9)
        {
            ft_putnbr_u(nb / 10);
            ft_putnbr_u(nb % 10);
        }
        else
            ft_putc(nb + '0');
    }
    return;
}

void ft_putnbr_limit(int nb, int x)
{
    //debug_number(nb, "nb");
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
    return;
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

/* void ft_put_X(long quotient)
{
    long remainder;
    char *hexadecimal;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    if (quotient == 0)
        ft_putc('0');
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- >0)
        ft_putc(ft_tolower(hexadecimal[j]));
    free(hexadecimal);
    return;
}

void ft_put_x(long quotient)
{
    long remainder;
    char *hexadecimal;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    if (quotient == 0)
        ft_putc('0');
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- >0)
        ft_putc(ft_tolower(hexadecimal[j]));
    free(hexadecimal);
    return;
} */
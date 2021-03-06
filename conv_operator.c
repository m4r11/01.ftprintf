/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 09:22:56 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/06 17:00:54 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c);

void ft_putnbr(int nb)
{
    if (nb <= INT_MAX && nb >= INT_MIN)
    {
        if (nb == INT_MIN)
        {
            ft_putchar('-');
            ft_putchar('2');
            ft_putnbr(147483648);
        }
        else if (nb < 0)
        {
            ft_putchar('-');
            ft_putnbr(-nb);
        }
        else if (nb > 9)
        {
            ft_putnbr(nb / 10);
            ft_putnbr(nb % 10);
        }
        else
        {
            ft_putchar(nb + '0');
        }
    }
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

void conv_itoa(t_type type, va_list args2)
{
    int x;
    x = va_arg(args2, int);
    ft_putnbr(x);
}
void conv_xtoa(t_type type, va_list args2)
{
    ft_putstr("xtoa");
}
void conv_uitoa(t_type type, va_list args2)
{
    ft_putstr("utoa");
}
void conv_ftoa(t_type type, va_list args2)
{
    ft_putstr("ftoa");
}
void conv_fetoa(t_type type, va_list args2)
{
    ft_putstr("fetoa");
}
void conv_dtoa(t_type type, va_list args2)
{
    ft_putstr("dtoa");
}
void print_str(t_type type, va_list args2)
{
    char *print;
    print = va_arg(args2, char *);
    ft_putstr(print);
}

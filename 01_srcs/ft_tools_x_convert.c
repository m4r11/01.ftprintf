/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_x_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:26:13 by user              #+#    #+#             */
/*   Updated: 2021/04/09 17:59:48 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_put_address(long long print)
{
   /*  long decimal; */
    long quotient;
    long remainder;
    char *hexadecimal;
    char *longmin;
    char *ulongmax;

    if (!(hexadecimal = malloc(sizeof(char *))))
        return;
    int j = 0;
    if (print == (long)LONG_MIN)
    {
        longmin = "0x8000000000000000";
        ft_putstr(longmin);
        free(hexadecimal);
        return ;
    }
    if (print == (long)ULONG_MAX)
    {
        ulongmax = "0xffffffffffffffff";
        ft_putstr(ulongmax);
        free(hexadecimal);
        return ;
    }
    quotient = print;
    ft_putc('0');
    ft_putc('x');
    if (quotient == 0)
        ft_putc('0');
    while (quotient != 0)
    {
     /*      debug_str(hexadecimal, "h");
        debug_number(quotient, "q"); */
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    while (j-- > 0)
        ft_putc(ft_tolower(hexadecimal[j]));
    free(hexadecimal);
    return;
}

int ft_hexlen(long print)
{
    long quotient;
    long remainder;
    char hexadecimal[20];
    if (print == 0)
        return(3);
    int j = 0;
    quotient = *(long *)&print;
    if (quotient == 0)
    {
        hexadecimal[0] = '0';
        j += 1;
    }
    else
    {
        hexadecimal[0] = '0';
        hexadecimal[1] = 'x';
        j += 2;
    }
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    //debug_number((ft_is_hex(hexadecimal)), "n hex");
    return (j);
}

int ft_xlen(long print)
{
    long quotient;
    long remainder;
    char hexadecimal[20];
    if (print == 0)
        return (3);
    int j = 0;
    quotient = print;
    while (quotient != 0)
    {
        if (quotient < 0)
            quotient = UINT_MAX - ((print * -1) - 1);
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
/*     debug_number(ft_is_hex(hexadecimal), "hex string len");
    debug_str(hexadecimal, "HEXADECIMAL"); */
    return (ft_is_hex(hexadecimal));
}

int		ft_is_hex(char *str)
{
	int i;
    int c;
	i = 0;
    c = 0;
	while (str[i] != '\0')
	{
		if(!(((str[i] >= 'A' && str[i] <= 'F' ) || (str[i] >= '0' && str[i] <= '9'))))
            break;
        else
            c++;
            i++;
	}
	return (c);
}
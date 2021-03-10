/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:40:48 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/09 18:28:12 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
	int r1, r2;
/* 	ft_putstr("%c ---------FLAG\n");
	r1 = (ft_printf("%c\n", '0'));
	ft_printf("%d\n", r1);
	r2 = (printf("%c\n", '0'));
	printf("%d\n", r2);
	ft_putstr("----------END\n");
	ft_putstr("%i ---------FLAG\n");
	r1 = (ft_printf("%d\n", 1111));
	ft_printf("%i\n", r1);
	r2 = (printf("%d\n", 1111));
	printf("%i\n", r2);
	ft_putstr("----------END\n");
	ft_putstr("%s ---------FLAG\n");	
	r1 = (printf("ola%sestas bem?\n", "mary"));
	ft_printf("%d\n", r1);
	r2 = (printf("ola%sestas bem?\n", "mary"));
	printf("%d\n", r2);
	ft_putstr("----------END\n");
	ft_putstr("----------TESTER TESTS\n");
	r1 = ft_printf("%s %s %s", "", "", "olajjjjjjjjjj");
	printf("r1 = %d\n", r1);
	r2 = printf("%s %s %s", "", "", "ola");
	printf("r2 = %d\n", r2);
     printf("----------2END\n");
	r1 = (ft_printf("%d\n", 1111));
	ft_printf("%d\n", r1); */
	r1 = (ft_printf(" % x\n", 0));
	r2 = (printf(" %x \n", 0));
	printf("%d\n", r1);
	printf("%d\n", r2);
	return (0);
}
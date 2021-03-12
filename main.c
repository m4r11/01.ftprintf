/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:40:48 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/12 00:04:32 by user             ###   ########.fr       */
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
	//r1 = (ft_printf("hello %-d, %-d\n", 9992, 999));
	r1 = (ft_printf("%-s\n","olasssss"));
	r1 = (ft_printf("%+d\n", 9992));
	r2 = (ft_printf("%#x\n", 9992));
	/*r2 = (ft_printf("%+f\n", 82.999));
	r1 = (ft_printf("%-d%-d\n", 9992, 999));
	r1 = (ft_printf("% d\n", 9992));
	r1 = (ft_printf("%hd\n", 9992));
	r1 = (ft_printf("%.d\n", 9992));
	r1 = (ft_printf("%-s", "hello")); */
	return (0);
}
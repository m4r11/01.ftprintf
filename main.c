/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 15:40:48 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/08 15:16:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./00_includes/ft_printf.h"
#include <limits.h>

int main()
{
	int r1;
	int r2;
	/* 	ft_printf("******************************\n");
	ft_printf("***         case c        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* 	printf("%-10c%*c%c*\n",'0', 10, '1', '2');
	ft_printf("%-10c%*c%c*\n",'0', 10, '1', '2'); */
	/* 	ft_printf("0%c\n", 0);
	printf("0%c\n", 0); */
	/* 	ft_printf("%*c\n", 0, '0');
	printf("%*c\n", 0, '0'); */
	/* 	ft_printf("%-c%-c%c*\n", 1, '0', 0);
	printf("%-c%-c%c*\n", 1, '0', 0); */
	/* 	ft_printf("%10c\n", '0');
	printf("%10c\n", '0'); */
	/* 	ft_printf(" -%*c* -%-*c* \n", -2, 0, 2, 0);
	printf(" -%*c* -%-*c* \n", -2, 0, 2, 0); */
	/* 	ft_printf("%c", '0');
	ft_printf("\n");
	ft_printf(" %c ", '0');
	ft_printf("\n"); */
	/* 	ft_printf("%*c", 1, '0');
	ft_printf("\n");
	printf("%-10c%*c%c*",'0', 10, '1', '2')
	ft_printf("\n"); */
	/* 	ft_printf("******************************\n");
	ft_printf("***         case s        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* 	ft_printf(" %-4s %4s \n", "123", "4567");
	printf(" %-4s %4s \n", "123", "4567");  */
	/* 	ft_printf("\n");
	ft_printf(" %*.s %.1s ", 10, "123", "4567");
	printf(" %*.s %.1s ", 10, "123", "4567");
	ft_printf("\n"); */
	/* 	ft_printf(" %*.3s %.3s ", 10, "123", "4567");
	printf(" %*.3s %.3s ", 10, "123", "4567"); */
	/* 	ft_printf(" %*.s %.1s \n", 10, "123", "4567");
	printf(" %*.s %.1s \n", 10, "123", "4567"); */
	/* 	ft_printf("\n");
	ft_printf(" %*.4s %.4s ", 10, "123", "4567");
	printf(" %*.4s %.4s ", 10, "123", "4567");
	ft_printf("\n"); */
	//r1 = printf(" %*.5s %*.5s \n", -10, "123", 10, "4567");
	/* 	printf(" %*.5s %*.5s \n", 10, "123", -10, "4567");
	ft_printf(" %*.5s %*.5s \n", 10, "123", -10, "4567"); */
	//ft_printf(" %-4s %4s ", "123", "4567");
	/* 	printf(" %0.s %0.s ", "123", "4567");
	ft_printf(" %0.s %0.s ", "123", "4567"); */
	/* 	printf(" %3.3s %3.3s \n", "123", "4567");
	ft_printf(" %3.3s %3.3s \n", "123", "4567"); */
	//ft_printf(" %4.3s %-4.3s ", "123", "4567");
	/* 	ft_printf(" %*.4s %.4s ", 10, "123", "4567");
	printf(" %*.4s %.4s ", 10, "123", "4567"); */
	/* 	ft_printf(" %4.2s %-4.2s ", "123", "4567");
	printf(" %4.2s %-4.2s ", "123", "4567"); */
	/* 	ft_printf(" %-3.s \n", NULL);
	printf(" %-3.s \n", NULL); */
	//printf(" %-9.1s ", NULL);
	/* 	printf(" %-9.1s ", NULL);
	ft_printf(" %-9.1s ", NULL); */
	/* 	ft_printf(" %.*s ", -2, NULL);
	printf(" %.*s ", -2, NULL); */
	//ft_printf(" %.*s ", -2, NULL);
	/* 	ft_printf(" %4.2s %-4.2s \n", "123", "4567");
	printf(" %4.2s %-4.2s \n", "123", "4567"); */
	//ft_printf(" %.*s ", 2, "9999");
	//ft_printf(" %*.s %.1s ", 10, "123", "4567");
	//ft_printf(" %.*s ", -2, NULL);
	//ft_printf("\n");
	//ft_printf(" %1s %1s \n", "123", "4567");
	//printf("\nr1 :%d \nr2 :%d", r1, r2);
	/* 	ft_printf("******************************\n");
	ft_printf("***         case i        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* 	ft_printf(" %-3.2i %10.42i \n", 0, 0);
	printf(" %-3.2i %10.42i \n", 0, 0); */
	/* 	ft_printf(" %-3.2i %10.42i \n", 10, -10);
	printf(" %-3.2i %10.42i \n", 10, -10); */
	/* 	ft_printf(" %-3.2i %10.42i \n", 1, -1);
	printf(" %-3.2i %10.42i \n", 1, -1); */
	/* 	ft_printf(" %-3.2i %10.42i \n", 10, -10);
	printf(" %-3.2i %10.42i \n", 10, -10); */
	/* 	ft_printf(" 0*%-0*.10i*0 0*%-0*.0i*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%-0*.10i*0 0*%-0*.0i*0 \n", 21, 1021, 21, -1011); */
	/* 	ft_printf(" --0*%0*.0i*0 0*%0*.10i*0-- \n", -21, INT_MAX, 21, INT_MIN);
	printf(" --0*%0*.0i*0 0*%0*.10i*0-- \n", -21, INT_MAX, 21, INT_MIN); */
	/* 	ft_printf("%010.1i\n", UINT_MAX + 1);
	printf("%010.1i\n", UINT_MAX + 1); */
	/* 	ft_printf(" 0*%0-*i*0 0*%0*i*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%0-*i*0 0*%0*i*0 \n", 21, 1021, 21, -1011); */
	/* 	ft_printf(" --0*%-0*.20i*0 0*%-0*.10i*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf(" --0*%-0*.20i*0 0*%-0*.10i*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN); */
	/* 	ft_printf("%03i\n", 0);
	printf("%03i\n", 0); */
	/* 	ft_printf("%1.i\n", 0);
	printf("%1.i\n", 0); */
	/* 	ft_printf("%09.0i\n", UINT_MAX + 1);
	printf("%09.0i\n", UINT_MAX + 1); */
	/* 	ft_printf("%09.i\n", UINT_MAX + 1);
	printf("%09.i\n", UINT_MAX + 1); */
	/* 	ft_printf(" --0*%-0*.2i*0 0*%-0*.2i*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN);
	printf(" --0*%-0*.2i*0 0*%-0*.2i*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN); */
	/* 	ft_printf(" 0*%0-*.*i*0 0*%0*.*i*0 \n", 6, 2, 102, 10, 21, -101);
	printf(" 0*%0-*.*i*0 0*%0*.*i*0 \n", 6, 2, 102, 10, 21, -101); */
	/* 	ft_printf(" *%*.*i* \n", 10, 21, -10);
	ft_printf(" *%-*.*i* *%*.*i*\n", 4, 5, 10, 10, 21, -10);
	printf(" *%-*.*i* *%*.*i*\n", 4, 5, 10, 10, 21, -10); */
	/* 	ft_printf(" *%-*.*i* *%*.*i* ", 4, 5, 10, 10, 21, -10);
	ft_printf("\n");
	printf(" *%-*.*i* *%*.*i* ", 4, 5, 10, 10, 21, -10); */
	/* ft_printf("******************************\n");
	ft_printf("***         case d        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n");
	ft_printf(" %.d ", 0);
	printf(" %.d \n", 0);*/
	/* 	ft_printf("******************************\n");
	ft_printf("***         case p        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* 	ft_printf(" %-10p %10p \n", 1, -1);
printf(" %p %p \n", 1, -1); ft_printf(" %p %p \n", 1, -1); */
	/* 	ft_printf(" %-10p %10p \n", 1, -1);
	printf(" %-10p %10p \n", 1, -1); */
	/* 	ft_printf(" %10p %10p \n", 1, -1);
	printf(" %10p %10p \n", 1, -1); */
	/* 	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf(" %p %p \n", LONG_MIN, LONG_MAX); */
	/* 	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf(" %p %p \n", ULONG_MAX, -ULONG_MAX); */
	/* 	ft_printf(" %*p %-*p \n", -10, 101, -10, 42);
	printf(" %*p %-*p \n", -10, 101, -10, 42); */
	/* 	ft_printf(" .-0*%*p %-*p*0-. \n", 11, 101, 11, 42);
	printf(" .-0*%*p %-*p*0-. \n", 11, 101, 11, 42); */
	/* 	ft_printf(" %10p %10p \n", 1, -1);
	printf(" %10p %10p \n", 1, -1); */
	/* 	ft_printf(" %10p %-10p \n", 1, -1);
	printf(" %10p %-10p \n", 1, -1); */
	/* 	ft_printf(" %-10p %-10p \n", 1, -1);
	printf(" %-10p %-10p \n", 1, -1); */
	/* 	ft_printf(" %10p %-10p \n", 0, 0);
	printf(" %10p %-10p \n", 0, 0); */
	/* 	ft_printf(" %*p %-*p \n", -10, 101, -10, 42);
	printf(" %*p %-*p \n", -10, 101, -10, 42); */
	//printf(" %10p %10p \n", 1, -1);
	/* 	ft_printf("******************************\n"); */
	/* 	ft_printf("***         case d        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* 	ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
	printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101); */
	/* 	ft_printf(" 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%0-*d*0 0*%0*d*0 \n", 21, 1021, 21, -1011); */
	/* 	ft_printf(" 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%-0*.10d*0 0*%-0*.0d*0 \n", 21, 1021, 21, -1011); */
	/* 	ft_printf(" --0*%-0*.20d*0 0*%-0*.10d*0-- \n", -21, CHAR_MAX, 21, CHAR_MIN); */
	/* 	ft_printf("%09.2d\n", UINT_MAX);
	printf("%09.2d\n", UINT_MAX);
	ft_printf("%09.10d\n", UINT_MAX);
	printf("%09.10d\n", UINT_MAX); */
	/* 	ft_printf("%010.0d\n", UINT_MAX);
	printf("%010.0d\n", UINT_MAX); */
	/* 	ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1);
	printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -2, 0, 21, 1); */
	/* 	printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN);
	ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, INT_MAX, 21, INT_MIN); */
	/* 	printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN);
	ft_printf(" --0*%0*.0d*0 0*%0*.10d*0-- \n", -21, LONG_MAX, 21, LONG_MIN); */
	/* 	ft_printf("******************************\n");
	ft_printf("***         case u        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* 	ft_printf(" %-1u \n", 0);
	printf(" %-1u \n", 0); */
	/* 	ft_printf(" %-3.2u %10.42u \n", 1, -1);
	printf(" %-3.2u %10.42u \n", 1, -1); */
	/* 	ft_printf(" %-3.2u %10.42u \n", 10, -10);
	printf(" %-3.2u %10.42u \n", 10, -10); */
	/* 	ft_printf(" %-3.2u %10.42u \n", 0, 0);
	printf(" %-3.2u %10.42u \n", 0, 0); */
	/* 	ft_printf(" *%*.*u* *%*.*u* \n", -6, 2, 102, 10, 21, 101);
	printf(" *%*.*u* *%*.*u* \n", -6, 2, 102, 10, 21, 101); */
	/* 	ft_printf" *%*.*u* *%*.*u* ", -6, 2, 102, 10, 21, 101));
	TEST(12, print(" 0*%0-*.*u*0 0*%0*.*u*0 ", 6, 2, 102, 10, 21, -101); */
	/* 	ft_printf(" 0*%0-*u*0 0*%0*u*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%0-*u*0 0*%0*u*0 \n", 21, 1021, 21, -1011); */
	/* 	ft_printf(" %-.2u \n", 0);
	printf(" %-.2u \n", 0);	 */
	/* 	ft_printf(" *%-*.*u* *%*.*u* \n", 4, 5, 10, 10, 21, -10);
	printf(" *%-*.*u* *%*.*u* \n", 4, 5, 10, 10, 21, -10);	 */
	/* 	ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 \n", 6, 2, 102, 10, 21, -101);
	printf(" 0*%0-*.*u*0 0*%0*.*u*0 \n", 6, 2, 102, 10, 21, -101);
 */
	/* 	ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 \n", 2, 6, 102, 21, 10, -101);
	printf(" 0*%0-*.*u*0 0*%0*.*u*0 \n", 2, 6, 102, 21, 10, -101); */
	/* 	ft_printf(" 0*%0-*.*u*0 0*%0*.*u*0 \n", 6, 2, 102, 10, 21, -101);
	printf(" 0*%0-*.*u*0 0*%0*.*u*0 \n", 6, 2, 102, 10, 21, -101); */
	/* 	ft_printf(" --0*%-0*.2u*0 0*%-0*.2u*0-- \n", -21, UINT_MAX, 21, UINT_MAX + 1);
	printf(" --0*%-0*.2u*0 0*%-0*.2u*0-- \n", -21, UINT_MAX, 21, UINT_MAX + 1); */
	/* 	ft_printf("%9.10u\n", UINT_MAX);
	printf("%9.10u\n", UINT_MAX); */
	/* 	ft_printf(" --0*%-0*.2u*0 0*%-0*.2u*0-- \n", -21, UINT_MAX, 21, UINT_MAX + 1);
	printf(" --0*%-0*.2u*0 0*%-0*.2u*0-- \n", -21, UINT_MAX, 21, UINT_MAX + 1); */
/* 	ft_printf("******************************\n");
	ft_printf("***         case x        ****\n");
	ft_printf("******************************\n");
	ft_printf("\n"); */
	/* static */  static char a01;
	/* static unsigned char a02;
	static short a03;
	static unsigned short a04;
	static int a05;
	static unsigned int a06;
	static long a07;
	static unsigned long a08;
	static long long a09;
	static unsigned long long a10;
	static char *a11;
	static void *a12; */

	static char *s_hidden = "hi low\0don't print me lol\0";
	static char *test;
	//ft_printf("%-70p\n", &a01);
	r1 = ft_printf("%.*i\n", 6, -3);
	r2 = printf("%.*i\n", 6, -3);
/*
ft_printf("%.*p\n", -3, &test);
	printf("%.*p\n", -3, &test); */
	/* 	you are at test 7 of x flag  */
	/* 	ft_printf(" *%-*.*X* *%*.*X* \n", 4, 5, 10, 10, 21, -10);
	printf(" *%-*.*X* *%*.*X* \n", 4, 5, 10, 10, 21, -10); */
	/* 	ft_printf("%*c\n", 2, '0');
	printf("%*c\n", 2, '0'); */
	//ft_printf("helllo %d  %s", 1990, "mary");
	//printf("%%*.s%10.4s*%ss\n", "1", "5");
	/* 	ft_printf("\n");
	printf("%%"); */
	/* 	printf(" %%  %%  %% "); */
	//printf(" %%  %%  %% \n");
	//printf(" %% \n");
	/* 	ft_printf(" %p \n", -1);
	printf(" %p \n", -1); */
	/* 	ft_printf(" %x \n", 0);
	printf(" %x \n", 0); */
	/* 	ft_printf(" %-.2x \n", 0);
	printf(" %-.2x \n", 0); */
	/* 	ft_printf("%10.10d\n", UINT_MAX);
	printf("%10.10d\n", UINT_MAX); */
	//ft_printf("%05d\n", 1199 );
	//printf("%05d\n", 0);
	/* 	ft_printf(" 0*%-0*.10x*0 0*%-0*.0x*0 \n", 21, 1021, 21, -1011);
	printf(" 0*%-0*.10x*0 0*%-0*.0x*0 \n", 21, 1021, 21, -1011); */
	/* 	ft_printf(" %x \n", 0);
	printf(" %x \n", 0); */
	/* 	ft_printf(" %21.42x \n", 123);
	printf(" %21.42x \n", 123); */
	/* 	ft_printf(" %-3.2x %10.42x \n", 0, 0);
	printf(" %-3.2x %10.42x \n", 0, 0); */
	/* 	ft_printf(" *%-*.*x* *%*.*x* \n", 4, 5, 10, 10, 21, -10);
	printf(" *%-*.*x* *%*.*x* \n", 4, 5, 10, 10, 21, -10); */
	/* 	ft_printf(" %-3.2x %10.42x \n", 1, -1);
	printf(" %-3.2x %10.42x \n", 1, -1); */
	/* 	ft_printf(" %-3.2x %10.42x \n", 10, -10);
	printf(" %-3.2x %10.42x \n", 10, -10); */
	/* 	ft_printf(" %-3.2x %10.42x \n", 1, -1);
	printf(" %-3.2x %10.42x \n", 1, -1); */
	/* 	ft_printf(" *%-*.*x* *%*.*x* \n", 6, 2, 102, 10, 21, -101);
	printf(" *%-*.*x* *%*.*x* \n", 6, 2, 102, 10, 21, -101); */
	/* 	ft_printf(" *%-*.*x* *%*.*x* \n", 4, 5, 10, 10, 21, -10);
	printf(" *%-*.*x* *%*.*x* \n", 4, 5, 10, 10, 21, -10); */
	return (0);
}

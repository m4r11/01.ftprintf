/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/10 19:24:05 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


/*
** enums for modularity: flags, format & size
*/
#define CONV_S "dixXufeEsScgopn"

typedef enum type_f
{
	d, // decimal int
	i, // int
	x, // int hex
	X, // int hex
	u, // unsiged int
	f, // float
	e, // float expon.
	E, // float expon.
	s, // string
	S, // string
	c, // single character
	g, // general format floating point
	o, // octal base 8
	p, // pointer
	n, // outpust # characters written
	END_FLAG
} type_f;

typedef enum format
{
	left_just,
	pad_zeros,
	plus_sign,
	minus_sign,
	deviant_op
} format;

typedef enum size_mod
{
	h,
	l,
	L
} size;

/*
** struct with general use variables 
*/

typedef struct s_struct
{
	char *str;
	char *f;
	char *next;
	char id;
	int i;
	int j;
	int c;
	int nbr;
	void *kind;
} t_struct;

static int lcounter; 

/*
**  argument type for function * 
*/

typedef struct s_type
{
	int nbr;
	void *kind;
	char *str;
} t_type;

/*
**  function * type def
*/

typedef void (*fptr)(t_type type, va_list args2);

/*
** func's_declared 
*/

void conv_itoa(t_type type, va_list args2);
void conv_xtoa(t_type type, va_list args2);
void conv_Xtoa(t_type type, va_list args2);
void conv_uitoa(t_type type, va_list args2);
void conv_ftoa(t_type type, va_list args2);
void conv_fetoa(t_type tyep, va_list args2);
void conv_fetoa(t_type type, va_list args2);
void conv_dtoa(t_type type, va_list args2);
void print_str(t_type type, va_list args2);
void print_c(t_type type, va_list args2);

/*
** ft_utilities.c
*/

void ft_putc(char c);
void ft_putstr(char *str);
char *ft_strdup(const char *s1);
int	ft_intlen_bonus(int);
int counter(int n);
int ft_arglen(va_list TYPE);
int ft_strlen(char *str);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_recursive_power(int nb, int power);

/*
** conv_numbers
*/

void ft_putnbr(int nb);
char *ft_itoa(int n);
bool is_base_valid(char *str);
void ft_putnbr_rebase(int number, int baseleng);
void ft_putnbr_base(int nbr, char *base);
void ft_putfloat(t_type type, va_list args2);

/*
** ft_printf.c
*/
int ft_printf(const char *format, ...);


/* 
**debugs
*/

void debug_str(char *s, char *name);
void debug_number(int i, char *name);

#endif

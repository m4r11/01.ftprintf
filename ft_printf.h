/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/06 17:15:55 by mvaldeta         ###   ########.fr       */
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

#define ARG(t_type) va_arg(args2, t_type)

/*
** enums for modularity: flags, format & size
*/
#define CONV_S "dixXufeEsSpn"

typedef enum type_f
{
	d, // int
	i,
	x,
	X,
	u,
	f,
	e,
	E,
	s,
	S,
	p,
	n,
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
	char *f;
	char *next;
	char id;
	int i;
	int j;
} t_struct;

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
void conv_uitoa(t_type type, va_list args2);
void conv_ftoa(t_type type, va_list args2);
void conv_fetoa(t_type tyep, va_list args2);
void conv_fetoa(t_type type, va_list args2);
void conv_dtoa(t_type type, va_list args2);
void conv_fetoa(t_type type, va_list args2);
void print_str(t_type type, va_list args2);
void print_str(t_type type, va_list args2);

/*
** ft_utilities.c
*/

void ft_putc(char c);
void ft_putstr(char *str);
int ft_strlen(char *str);

/*
** conv_numbers
*/

void ft_putnbr(int nb);
char *ft_itoa(int n);
bool is_base_valid(char *str);
void ft_putnbr_base_recursiva(int number, char *base, int baseleng);
void ft_putnbr_base(int nbr, char *base);

/*
** ft_printf.c
*/
int ft_printf(char *format, ...);

/*
** debugs
*/
void debug_str(const char *s, char *name);
void debug_number(int i, char *name);

#endif

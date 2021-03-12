/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/11 19:39:42 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_directives.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>

/*
** enums for modularity: flags, format & size
** 
*/

# define CONV_S "dixXufeEsScgopn"

typedef enum e_ty
{
	d,x,X,u,f,e,E,s,S,c,g,o,p,n,M,END_FLAG
}			t_ty;

# define DIR_S "-+ 0hljz.#123456789"

typedef enum e_dir 
{
    POSITION,
    SIGN,
    SPACESIGN,
    ZERO,
    SHORT,
    LONG,
    UINTMAX,
    UNSIGNED,
    PRECISION,
    ALTERNATE, 
    FIELD,
    END_DIR,
}			t_dir;


/*
** struct with general use variables 
*/
typedef struct s_struct
{
	char *str;
	char *temp;
	char *next;
	char id;
	int i;
	int j;
	int c;
	int nbr;
	void *kind;
} t_struct;

/*
**  argument type for function, this will be something else
** 	it's juts a placeholder in function 
*/

typedef struct s_type
{
	int nbr;
	void *kind;
	char *str;
} t_type;

/*
**  function * type def for conversion
*/

typedef void (*fptrconv)(char *formatting, va_list args2);
typedef void (*fptrdir)(char *dir);

/*
**  conversion func's_declared 
*/

void conv_itoa(char *formatting, va_list args2);
void conv_xtoa(char *formatting, va_list args2);
void conv_Xtoa(char *formatting, va_list args2);
void conv_uitoa(char *formatting, va_list args2);
void conv_ftoa(char *formatting, va_list args2);
void conv_fetoa(char *formatting, va_list args2);
void conv_fetoa(char *formatting, va_list args2);
void conv_dtoa(char *formatting, va_list args2);
void print_str(char *formatting, va_list args2);
void print_c(char *formatting, va_list args2);

/*
**  format directives func's_declared 
*/

void    put_position(char *dir);
void    put_sign(char *dir);
void    put_space(char *dir);
void    put_zeroes(char *dir);
void    put_len(char *dir);
void    put_dec_precision(char *dir);
void    put_alternate(char *dir);
void    put_field(char *dir);

char *has_formating(char *format, int n);
int  get_index(char *s1, char *s2);

/*
** ft_utilities.c
*/

void ft_putc(char c);
void ft_putstr(char *str);
char *ft_strdup(const char *s1);
int ft_intlen_bonus(int);
int counter(int n);
int ft_arglen(va_list TYPE);
int ft_strlen(char *str);
int ft_tolower(int c);
int ft_toupper(int c);
int ft_recursive_power(int nb, int power);
char	*ft_strchr(const char *s, int c);

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

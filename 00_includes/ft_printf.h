/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/04/09 18:02:07 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "ft_deploy_format.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

#define NO_FORMAT -1
#define FAIL -7
#define LETTER 1
#define END -3
#define END_STRING -2

va_list args;
va_list args2;

/*
** string to fetch precision
*/
#define PRE_S "123456789"

/*
** string to fetch types
*/
#define CONV_S "dixXufeEsScgopn"

/*
** complete DIR_S
*/
#define DIR_S "*-+ 0hljz.#123456789"

/*
** simplified DIR_S wihtout the space for middle_print function 
*/
#define DIR2_S "*-+0hljz.#123456789"

/*
** enums for modularity: flags, format & size
*/
typedef enum e_flag
{
	d,
	i,
	x,
	X,
	u,
	f,
	e,
	E,
	s,
	S,
	c,
	g,
	o,
	p,
	n,
	M,
	END_FLAG
} t_flag;

typedef enum e_dir
{
	STAR,
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
} t_dir;

/*
** struct for general purpose variables used in main printf.c
*/
typedef struct s_struct
{
	char	*str;
	char	*temp;
	char	*next;
	char	id;
	int		n;
	int		i;
	int		j;
	int		c;
	int		nbr;
	void	*kind;
} t_struct;

typedef struct s_type
{
	int		nbr;
	void	*kind;
	char	*str;
} t_type;

/*
** struct for "directives" variables 
*/
typedef struct s_dir_variables
{
	int		i;
	int		j;
	int		len;
	int		x;
	int		has_zero;
	int		dot;
	int		q;
	int		min_c;
	int		min;
	int		start;
	int		to_pad;
	int		flag;
	long	l;
	long	hex;
	char	*temp;
	char	*verify;
	char	*print;

} t_dir_variables;

/*
**   new funcs to organize per type
*/

int		find_width_d(char *dir, int start, va_list args2);
int		put_string_pad_right_limit(char *print, int to_pad, int min_c);
int		put_string_pad_left(char *print, int to_pad);
int		put_string_pad_right(char *print, int to_pad);
int		put_string_pad_left_limit(char *print, int to_pad, int min_c);
int		ft_zerochr(char *, int start);
int		print_string(char *s, int c, int start);
int		ft_is_hex(char *str);
int		find_precision(char *dir, int start, va_list args2);

/* c */
int		print_c(char *input, int i, int has_format, va_list args2);
int    ft_pad_left_printc_after_zero(int print, int to_pad);
int    ft_pad_left_printc_after(int print, int to_pad);
int    ft_printc_pad_right(int print, int to_pad);


/* s */

int		find_width_c(char *dir, int start, va_list args2);
int		pad_right_c(int print, int to_pad, int min_c);
int		pad_left_c(int print, int to_pad, int min_c, int zero);
int		format_c(int print, int to_pad, int min_c, int zero);

/* di */
int		ft_pad_right(int print, int to_pad, int min_c);
int		ft_pad_left_no_min_no_zero(int print, int to_pad, int min_c);
int		ft_pad_left_no_min_zero(int print, int to_pad, int min_c);
int		ft_pad_left_minor_min(int print, int to_pad, int min_c);
int		ft_pad_left_bigger_pad(int print, int to_pad, int min_c);
int		ft_pad_left_putnbr_min(int print, int to_pad, int min_c);
int		ft_pad_left_putnbr_zero(int print, int to_pad, int min_c);
int		ft_pad_left_putnbr(int print, int to_pad, int min_c);
int		pad_left_ints(int print, int to_pad, int min_c, int zero);
int 	pad_right_ints(int print, int to_pad, int min_c, int zero);
void 	ft_putnbr_up(int print, int min_c);

/* s */
int		format_string(char *print, int to_pad, int min_c, int zero);
int		null_string(char *print, int to_pad, int min_c);
int		pad_left_s(char *print, int to_pad, int min_c);
int		pad_right_s(char *print, int to_pad, int min_c, int zero);

/* p */

int		ft_pad_right_nominc_p(long long print, int to_pad, int min_c);
int		ft_pad_left_big_pad_p(long long print, int to_pad, int min_c);
int		ft_pad_left_no_zero_p(long long print, int to_pad, int min_c);
int		find_width_p(char *dir, int start, va_list args2);
int		format_address(long long sprint, int to_pad, int min_c, int zero);
int		pad_left_p(long long print, int to_pad, int min_c, int zero);
int		pad_right_p(long long print, int to_pad, int min_c);
void 	ft_put_address_up(long long print, int min_c);
void	ft_put_address(long long print);
int		ft_hexlen(long print);
int		ft_edge_cases_p(long long print, int min_c);
void	ft_min_c(long long print, int min_c, int len);

/* u */
int		ft_pad_left_u(int print, int to_pad, int min_c, int zero);
int		format_u(unsigned int print, int to_pad, int min_c,int zero);
int		ft_pad_left_len_u(int print, int to_pad, int min_c, int c);
int		ft_pad_right_u(int print, int to_pad, int min_c);
void	ft_putnbr_u_up(unsigned nb, int min_c);

/* x */
int		pad_right_x(t_dir_variables var);
int		pad_left_x(t_dir_variables var);
int		ft_pad_right_no_min_x(t_dir_variables var);
int		ft_pad_right_not_zero_x(t_dir_variables var);
int		ft_pad_right_zero_x(t_dir_variables var);
int		ft_pad_right_x(t_dir_variables var, int size, int c);
int		ft_pad_left_big_min(t_dir_variables var);
int		ft_pad_left_big_pad(t_dir_variables var);
int		ft_no_minc_no_zero_x(t_dir_variables var);
int		ft_has_zero_x(t_dir_variables var);
int		ft_no_minc_zero_x(t_dir_variables var);
int		ft_pad_left_x(t_dir_variables var, int size,  int c);
int		format_x(t_dir_variables var);
void	ft_put_x_up(long print, int min_c, int width);

/* X */

int format_X(long print, int to_pad, int min_c, int zero);

/*
**  function * type def for conversion
*/

typedef int (*fptrconv)(char *input, int index, int has_format, va_list args2);
typedef char (*fptrdir)(char *dir, va_list args2, int flag);

/*
**  printing type pointer func's_declared 
**  typedef void (*fptrconv)(char *input,  int index, int has_format, va_list args2);
*/

int		conv_itoa(char *input, int index, int has_format, va_list args2);
int		conv_dtoa(char *input, int index, int has_format, va_list args2);
int		conv_xtoa(char *input, int index, int has_format, va_list args2);
int		conv_Xtoa(char *input, int index, int has_format, va_list args2);
int		conv_uitoa(char *input, int index, int has_format, va_list args2);
int		conv_ftoa(char *input, int index, int has_format, va_list args2);
int		conv_fetoa(char *input, int index, int has_format, va_list args2);
int		conv_fetoa(char *input, int index, int has_format, va_list args2);
int		conv_dtoa(char *input, int index, int has_format, va_list args2);
int		print_str(char *input, int index, int has_format, va_list args2);
int		print_c(char *input, int index, int has_format, va_list args2);
int		conv_otoa(char *input, int index, int has_format, va_list args2);
int		print_ptr(char *input, int index, int has_format, va_list args2);
int		print_n(char *input, int index, int has_format, va_list args2);
int		print_percent(char *input, int index, int has_format, va_list args2);

/*
**  other  func's_declared 
*/

char has_formating(char *format, int n, va_list args2, int flag);
int get_index(char *s1, char *s2);

/*
** ft_general_utilities.c
*/
void	ft_putc(char c);
void	ft_putstr(char *str);
char	ft_putstr_limit(char *str, int limit);
char	*ft_strdup(const char *s1);
int		ft_intlen(int);
int		counter(int n);
int		ft_arglen(char *search);
int		ft_strlen(char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_recursive_power(int nb, int power);
char	*ft_strchr(const char *s, int c);
int		ft_str_is_numeric(char *str);
int		ft_atoi(const char *str);
char	print_x_times(int n, char c);
int		loop_through(char *flags, char *format, int a);
int		ft_isalpha(int c);
int		ft_simple_atoi(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strnew(size_t size);
int		arg_number(char *to_parse);
int		ft_intstrchr(char *s, int c, int start);
int		ft_putcharfrom(char *s, int start, char flag);
int		ft_intstrchr_flag(char *s, int c, int start);
int		find_first_flag(char *input);
int		print_the_middle(char *input, int flag1_end, char flag);
int		find_width(char *dir, int start, va_list args2);


/*
** conv_numbers & other number related utilities 
*/
void	ft_putnbr(int nb);
char	*ft_itoa(int n);
void	ft_putfloat(t_type type, va_list args2);
void	ft_putnbr_limit(int nb, int x);
void	ft_putnbr_u(unsigned int nb);
void	ft_put_x(long print, int flag);
int		ft_isdigit(int c);
int		ft_u_intlen(unsigned int n);
int		ft_xlen(long print);

/*
** parse_directives.c
*/
int loop_for_directives( char *format, int j);

/*
** ft_printf.c
*/
int ft_printf(const char *format, ...);
int parse(char *to_parse, int i);

/* 
**debugs
*/
void debug_str(char *s, char *name);
void debug_number(int i, char *name);

#endif

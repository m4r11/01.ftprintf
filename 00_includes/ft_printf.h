/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/31 17:21:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_deploy_format.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>

# define NO_FORMAT -1
# define FOUND 
# define LETTER 1
# define END -3

va_list args;
va_list args2;

/*
** string to fetch precision
*/
# define PRE_S "123456789"

/*
** string to fetch types
*/
# define CONV_S "dixXufeEsScgopn"

/*
** complete DIR_S
*/
# define DIR_S "*-+ 0hljz.#123456789"

/*
** simplified DIR_S wihtout the space for middle_print function 
*/
# define DIR2_S "*-+0hljz.#123456789"

/*
** enums for modularity: flags, format & size
*/
typedef enum e_flag
{
	d,i,x,X,u,f,e,E,s,S,c,g,o,p,n,M,END_FLAG
}			t_flag;

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
}			t_dir;

/*
** struct for general purpose variables used in main printf.c
*/
typedef struct s_struct
{
	char *str;
	char *temp;
	char *next;
	int n;
	char id;
	int i;
	int j;
	int c;
	int nbr;
	void *kind;
} t_struct;

/*
** struct for "directives" variables 
*/
typedef struct s_dir_variables
{
    int i;
    int j;
    int len;
	int x;
    int x1converted;
    int x1len;
    int converted;
	int new;
	int min_c;
	int real;
	int start;
	int width;
	int passflag;
	long *hex;
    char *x1;
    char *temp;
    char *verify;
	char *print;

} t_dir_variables;

/*
**  argument type for function, this will be something else
** 	it's juts a placeholder in function, can del this now
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
typedef void (*fptrconv)(char *input, int has_format, va_list args2);
typedef char (*fptrdir)(char *dir, va_list args2, int flag);

/*
**  conversion func's_declared 
*/
void conv_itoa(char *input, int has_format, va_list args2);
void conv_xtoa(char *input, int has_format, va_list args2);
void conv_Xtoa(char *input, int has_format, va_list args2);
void conv_uitoa(char *input, int has_format, va_list args2);
void conv_ftoa(char *input, int has_format, va_list args2);
void conv_fetoa(char *input, int has_format, va_list args2);
void conv_fetoa(char *input, int has_format, va_list args2);
void conv_dtoa(char *input, int has_format, va_list args2);
void print_str(char *input, int has_format, va_list args2);
void print_c(char *input, int has_format, va_list args2);
void conv_otoa(char *input, int has_format, va_list args2);
void print_ptr(char *input, int has_format, va_list args2);
void print_n(char *input, int has_format, va_list args2);

/*
**  format directives func's_declared 
*/
char    put_star(char *dir, va_list args2, int flag);
char   	put_position(char *dir, va_list args2, int flag);
char    put_sign(char *dir, va_list args2, int flag);
char    put_space(char *dir, va_list args2, int flag);
char    put_zeroes(char *dir, va_list args2, int flag);
char    put_len(char *dir, va_list args2, int flag);
char    put_dec_precision(char *dir, va_list args2, int flag);
char    put_alternate(char *dir,va_list args2, int flag);
char    put_field(char *dir,va_list args2, int flag);

char	*has_formating(char *format, int n, va_list args2, int flag);
int 	get_index(char *s1, char *s2);


/*
** position.c
*/
char    position_address(char *dir, va_list args2);
void 	ft_put_address(char *input, long *print);
int		ft_hexlen(long *print);


/*
** micro_field_tools.c
*/
char    put_spaces_before_s(char *x1, int converted, int len);
char    put_spaces_afer_s(char *x1, int converted, int len);
char    put_spaces_before_c(int x, int converted);
char    put_spaces_afer_c(int x, int converted);

/*
** field_tools.c
*/
char    ft_copy(char *s1, char *s2);
char    ft_minor_field_star_fetch(va_list args2, int x, int converted);

/*
** field.c
*/
char	field_c_combos(char *dir,va_list args2);
char	field_c(char *dir,va_list args2);
char	field_s(char *dir,va_list args2);
char    field_int_combos(char *dir, va_list args2);
char    field_u(char *dir, va_list args2);
char 	field_u_combos(char *dir, va_list args2);
char    put_spaces_before_u(int x, int converted);
char    put_spaces_afer_u(int x, int converted);


/*
** star.c
*/
char    star_s(char *dir, va_list args2);

/*
** micro_precision_tools.c
*/
char	ft_micro_great_width_less_print(int width, int min_c, int print, int len);
char	ft_micro_great_width_great_len(int width, int min_c, int len);
char	ft_print_null(char *print, int width, int min_c);
char 	ft_micro_same_len(char *print, int width, int min_c);
char    ft_wrong_directive(char *dir, char *print, int width, int min_c);
char 	ft_micro_less_len(char *print, int width, int min_c);
char    ft_micro_less_width(char *print, int width, int min_c);
/*
** micro_precision__utools.c
*/
char	ft_micro_great_width_less_print_u(int width, int min_c, int print, int len);
char	ft_micro_great_width_great_len_u(int width, int min_c, int len);
char	ft_print_null_u(char *print, int width, int min_c);
char 	ft_micro_same_len_u(char *print, int width, int min_c);
char    ft_wrong_directive_u(char *dir, char *print, int width, int min_c);
char 	ft_micro_less_len_u(char *print, int width, int min_c);
char    ft_micro_less_width_u(char *print, int width, int min_c);

/*
** precision_tools.c
*/
char	zero_min_c(int len, int min_c, int width, int print);
char    minor_len(int len, int min_c, int width, int print);
char    greater_len(int len, int min_c, int width, int print);
char	precision_op(int len, int min_c, int width, int print);
char	zero_min_c_u(int len, int min_c, int width, int print);
char    minor_len_u(int len, int min_c, int width, int print);
char    greater_len_u(int len, int min_c, int width, int print);
char	precision_op_u(int len, int min_c, int width, int print);
char 	zero_minus_star_dot_star_u(va_list args2);
char zero_star_u(va_list args2);
char zero_simple_star_u(va_list args2);

/*
** precision.c
*/
char    precision_s(char *dir,va_list args2);
char    precision_int(char *dir,va_list args2);
char	precision_int_combos(char *dir, va_list args2, int flag);
char 	precision_u_combos(char *dir, va_list args2);
char 	precision_u(char *dir, va_list args2);

/*
** zero.c
*/
char    zero_int_combos(char *dir, va_list args2);
char	zero_star_dot_star(va_list args2);
char 	zero_star_dot_digi(va_list args2, char *to_convert);
char	zero_star_flag(va_list args2);
char 	zero_2digi_dot_flag(va_list args2, char *to_convert);
char 	zero_1digit_dot_flag(va_list args2, char *to_convert);
char    zero_u_combos(char *dir, va_list args2);
char	zero_star_dot_star_u(va_list args2);
char 	zero_star_dot_digi_u(va_list args2, char *to_convert);
char	zero_star_flag_u(va_list args2);
char 	zero_2digi_dot_flag_u(va_list args2, char *to_convert);
char 	zero_1digit_dot_flag_u(va_list args2, char *to_convert);

/*
** ft_general_utilities.c
*/
void	ft_putc(char c);
void	ft_putstr(char *str);
char	ft_putstr_limit(char *str, int limit);
char	*ft_strdup(const char *s1);
int		ft_intlen(int);
int		counter(int n);
int 	ft_arglen(char * search);
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
int		print_the_middle(char *input, int flag1_end);
int     find_width(char *dir, int start);
int		ft_isdigit(int c);
int		ft_u_intlen(unsigned int n);

/*
** conv_numbers
*/
void ft_putnbr(int nb);
char *ft_itoa(int n);
bool is_base_valid(char *str);
void ft_putnbr_rebase(int number, int baseleng);
void ft_putnbr_base(int nbr, char *base);
void ft_putfloat(t_type type, va_list args2);
void ft_putnbr_limit(int nb, int x);
void ft_putnbr_u(unsigned int nb);
/*
** parse_directives.c
*/
int    loop_for_directives(char *flags, char *format, int j);


/*
** ft_printf.c
*/
int ft_printf(const char *format, ...);
int	parse(char *to_parse, int i);

/* 
**debugs
*/
void debug_str(char *s, char *name);
void debug_number(int i, char *name);


#endif

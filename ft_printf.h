/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:57:25 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/02 18:51:18 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (｡◕‿◕｡)
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> /* va_list, va_start, va_arg, va_end */
# include <stdio.h>

//typedef enum 		type_f;
enum				type_f
{
	d, i, x, X, u, f, e, E, s, S, p, n
}type_f;

typedef enum 		format;
enum				format
{
	left_just, pad_zeros, plus_sign, minus_sign, deviant_op
}format;

typedef enum		size_mod;
enum				size_mod
{
	h, l, L
}size;

typedef int (*ft_treat)(const char *literal, ...);

/*
** variable struct
*/
typedef	struct		s_var
{
	char	*tmp;
	int		i;
	size_t	len;
	int		e_index;
}					t_var;
/*
** ft_printf.c
*/
int					ft_printf(const char *format, ...);
/*
** ft_treat.c
*/
char				*ft_no_leaks(char *str, char *temp);
int					get_next_line(int fd, char **line);
int					ft_delete (char **del);

#endif

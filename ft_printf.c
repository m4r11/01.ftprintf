 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 22:11:39 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/09 18:09:35 by mvaldeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_directives.h"

static fptrconv get_converter[] =
	{
		&conv_itoa,
		&conv_itoa,
		&conv_xtoa,
		&conv_Xtoa,
		&conv_uitoa,
		&conv_ftoa,
		&conv_fetoa,
		&conv_fetoa,
		&print_str,
		&print_str,
		&print_c,
		&conv_fetoa,
		//&conv_otoa,
		//&print_ptr,
		//&print_n,

};

int  get_index(char *s1, char *s2)
{
    int j = 0;
	int mini_index = INT_MAX;
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int i = 0;
    while(i < len2)
    {	
		i++;
		j = -1;
        while(j<len1)
        {
			j++;
            if(s2[i] == s1[j] && j < mini_index)
            {
				mini_index = j;
                return(j);
				break;
            }
        }
    }
    return(j);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	va_list args2;
	t_struct v;
	t_type type;
	int r;

	va_start(args, format);
	va_copy(args2, args);

	v.temp = ft_strdup(format);
	v.i = 0;
	while (v.temp[v.i])
	{
		if (v.temp[v.i] != '%')
			ft_putc(v.temp[v.i]);
		else
		{
			v.i++;
			v.c = 0;
			v.j = 0;
			has_formating(v.temp, get_index(DIR_S, v.temp));
			v.i++;
			while(CONV_S[v.j])
			{
				if(CONV_S[v.j] == v.temp[v.i])
					get_converter[v.j](DIR_S, args2);
				v.j++;
			}				
		}
		v.i++;
	}
	va_end(args);
	free(v.temp);
	return (counter(0));
}
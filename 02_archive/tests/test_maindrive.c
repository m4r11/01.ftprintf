/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_maindrive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:34:40 by user              #+#    #+#             */
/*   Updated: 2021/04/05 18:00:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mvaldeta/42/42Cursus/01.ftprintf/00_includes/ft_printf.h"

# define CONV_S "dixXufeEsScgopn"
# define DIR2_S "*-+0hljz.#123456789"

void ft_putc(char c)
{
	write(1, &c, 1);
    return;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

int		ft_intstrchr_flag(char *s, int c, int start)
{
	int i;
	i = start;
	while(s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return(i);
	return(-1);
}

int		ft_intstrchr(char *s, int c, int start)
{
	int i;
	i = start;
	if (s[start] == c)
		i++;
	while(s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return(i);
	return(-1);
}

int    print_string(char *s, int c, int start)
{
    while(s[start] != c)
    {
        ft_putc(s[start]);
        start++;
    }
    return(start);
}


int     main()
{
    int middle, r2, r3;
    int i;
    int start;
    int end;
    char *s, *s2, *s3;
    char *input;
    char *input2;
    char *input3;
    char *input4;
    input = "olaan %-4s somos %4s ";
    input2 = " %-4s  %-4s ";
    input3 = "%-10c%*c%c*";
    input4 = "%%*.s%10.4s*%ss\n";

   r2 = print_string(input, '%', 0);
   printf(" stops at: %d", r2);


}
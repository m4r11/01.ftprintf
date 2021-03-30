/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:20:24 by mvaldeta          #+#    #+#             */
/*   Updated: 2021/03/30 15:58:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putc(char c)
{
	write(1, &c, 1);
	counter(1);
}

void ft_putstr(char *str)
{
	t_struct v;
	int i;

	i = 0;
	while ((str[i]) != '\0')
	{
		ft_putc(str[i]);
		++i;
		//counter(1);
	}
}

/* char ft_putstr_limit(char *str, int limit)
{
	t_struct v;
	int i;

	i = 0;
	while ((str[i]) < str[limit])
	{
		ft_putc(str[i]);
		++i;
		//counter(1);
	}
	return(0);
} */

int ft_strlen(char *str)
{
	if (!str)
		return(0);
	int x;
	x = 0;
	while (str[x] != '\0')
	{
		++x;
	}
	return (x);
}

int ft_arglen(char * search)
{
	int count;
	count = 0;
	while(*search)
	{
		if (*search == '%')
			count +=1;
	search++;
	}
return(count);	
}

int ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

int ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

int ft_intlen(int n)
{
	int len;
	len = 1;
	if (n < 0)
	{
		len = 2;
		n *= -1;
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return(len);
	}
	else 
	{
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return (len);
	}
	return(-1);
}

int ft_u_intlen(unsigned int n)
{
	int len;
	len = 1;
	if (n < 0)
	{
		len = 2;
		n *= -1;
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return(len);
	}
	else 
	{
		while (n > 9)
		{
			len++;
			n /=10;
		}
		return (len);
	}
	return(-1);
}

int ft_recursive_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	if (power != 0)
	{
		result = nb * ft_recursive_power(nb, power - 1);
	}
	return (result);
}

char *ft_strdup(const char *s1)
{
	char *s2;
	size_t i;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

int counter(int n)
{
	static int res = 0;

	res += n;
	return(res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

/* int		ft_intstrchr(char *s, int c, int start)
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
} */

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_ratoi(const char *str, int i)
{
	if (!*str || *str > '9' || *str < '0')
		return (i);
	i = i * 10 + (*str - '0');
	return (ft_ratoi(++str, i));
}

int			ft_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		return (-ft_ratoi(++str, 0));
	if (*str == '+')
		return (ft_ratoi(++str, 0));
	return (ft_ratoi(str, 0));
}

int			ft_simple_atoi(const char *str)
{
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
	*str == '\f' || *str == '\r' || *str == '-')
		str++;
	return (ft_ratoi(str, 0));
}

/* char	*print_x_times(int n, char c)
{
	//debug_number(n, "convertedn");
	while (n > 0)
	{
		ft_putc(c);
		n--;
	}
	return(0);
} */

/* int  get_index(char *s1, char *s2)
{
    int j;
	int mini_index = INT_MAX;
	int len1 = ft_strlen(s1);
	char *start = ft_strchr(s2, '%');
	//debug_str(start, "start");
	int len2 = ft_strlen(start);
	//debug_number(len1, "len1");
	int i = 0;
    while(i < len2)
    {	
		i++;
		j = 0;
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
	if (mini_index != j)
		return(NO_FORMAT);
    return(0);
}
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst && !src)
		return (0);
	i = 0;
	if ((size_t)dst - (size_t)src < len)
	{
		i = len - 1;
		while (i >= 0 && i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (size--)
	{
		*(str++) = '\0';
		i++;
	}
	*str = '\0';
	return (str - i);
}

int arg_number(char *to_parse)
{
	int i;
	int counter;
	counter = 0;
	i = 0;
	while(*to_parse)
	{
		if(*to_parse == '%')
			counter +=1;
		to_parse++;
	}
	return(counter);
}

/* int		ft_putcharfrom(char *s, int start, char *dir, char *flag)
{
	int i;
	i = start;
    int j; 
    int k;
    int len = 0;
    while(s[i] != '\0')
    {
        j = 0;
        while(dir[j] != '\0')
        {
            if (dir[j] == s[i])
            {
                len+=1;
                break;
            }
            j++;
        }
        k = 0;
        while(flag[k] != '\0')
        {
            if (flag[k] == s[i])
            {
                len+=1;
                break;
            }
            k+=1;
        }
        i++;
    }
	return(len);
}
 */
/* int		ft_intstrchr_flag(char *s, int c, int start)
{
	int i;
	i = start;
	while(s[i] != '\0' && s[i] != c)
		i++;
	if (c == s[i])
		return(i);
	return(-1);
} */

/* int find_first_flag(char *input)
{
    int i;
    int j;
    int flag1_end;
    int percent1;
    int percent2;

    percent1 = ft_intstrchr_flag(input, '%', 0);
    percent2 =  ft_intstrchr(input, '%', percent1);
    flag1_end = percent2;
    while(input[flag1_end])
    {
        i = 0;
        while (CONV_S[i])
        {
             if(CONV_S[i] == input[flag1_end])
             {
                 j = 0;
                 while(DIR2_S[j])
                 {
                     if ((DIR2_S[j] == input[flag1_end-1]) || '%' == input[flag1_end-1])
                         return(flag1_end + 1);
                    j++;
                 }
             }
            i++;
        }
        //printf("this is the end:%d\n", flag1_end);
        flag1_end--;
    }
    return(0);
} */

/* int   print_the_middle(char *input, int flag1_end)
{
    int start;
    int middle;
    int end;

    start = ft_intstrchr_flag(input, '%', 0);
    //printf("start : %d\n" ,start);
    end = ft_intstrchr(input, '%', start);
    //printf("end : %d\n", end);
    middle = flag1_end;
    //printf("middle : %d\n", middle);
    if (middle == 0)
        return(0);
    while(input[middle] != input[end])
    {
            ft_putc(input[middle]);
            middle++;
    }
    return(0);
} */
/* 
int     find_width(char *dir, int start)
{
    int width;

    if (dir[start + 1] == '-')
       return(width = (ft_simple_atoi(&dir[start+2]) * -1));
    if (ft_isdigit(dir[start + 1]) == 1)
        return(width = ft_simple_atoi(&dir[start+1]));
    return(0);
}
 */
/* int find_first_flag(char *input)
{
    int i;
    int j;
    int flag1_end;
    int percent1;
    int percent2;

    percent1 = ft_intstrchr_flag(input, '%', 0);
    percent2 =  ft_intstrchr_flag(input, '%', percent1);
    flag1_end = percent2;
    while(input[flag1_end])
    {
        i = 0;
        while (CONV_S[i])
        {
             if(CONV_S[i] == input[flag1_end])
             {
                 j = 0;
                 while(DIR2_S[j])
                 {
                     if (DIR2_S[j] == input[flag1_end-1])
                         return(flag1_end + 1);
                    j++;
                 }
             }
            i++;
        }
        //printf("this is the end:%d\n", flag1_end);
        flag1_end--;
    }
    return(0);
}

int   print_the_middle(char *input, int flag1_end)
{
    int start;
    int middle;
    int end;

    start = ft_intstrchr_flag(input, '%', 0);
    //printf("start : %d\n" ,start);
    end = ft_intstrchr_flag(input, '%', start);
    //printf("end : %d\n", end);
    middle = flag1_end;
    while(input[middle] != input[end])
    {
            ft_putc(input[middle]);
            middle++;
    }
    return(0);
} */

/* int find_first_flag(char *input)
{
    int i;
    int j;
    int flag1_end;
    int percent1;
    int percent2;

    percent1 = ft_intstrchr(input, '%', 0);
    percent2 =  ft_intstrchr(input, '%', percent1);
    flag1_end = percent2;
    while(input[flag1_end])
    {
        i = 0;
        while (CONV_S[i])
        {
             if(CONV_S[i] == input[flag1_end])
             {
                 j = 0;
                 while(DIR2_S[j])
                 {
                     if (DIR2_S[j] == input[flag1_end-1])
                         return(flag1_end + 1);
                    j++;
                 }
             }
            i++;
        }
        //printf("this is the end:%d\n", flag1_end);
        flag1_end--;
    }
    return(0);
}

int   print_the_middle(char *input, int flag1_end, int start)
{
    int middle;
    int end;

    start = ft_intstrchr(input, '%', start);
    end = ft_intstrchr(input, '%', start);
    middle = flag1_end;
    while(input[middle] != input[end])
    {
            ft_putc(input[middle]);
            middle++;
    }
    return(0);
} */


/* char print_the_rest(char *input, int start, int end)
{
	t_flag f;
	int i; 
	i = 2;
	while(start != 's')
		start++; 
	debug_number(p, "enum p");
	printf("start here : %d", SIGN);
	if(input[i] != '%' || input[i] != '\0')
	{
		if (input[i] != 'c')
			ft_putc(input[i]);
		i++;
	}
    return(0);
}  */



/* char	print_the_rest(char *input, int start, int end)
{
	static int i;
	i = start+=1;
	//debug_number(i, "statici");
	while((input[i] && input[i] != 's' || input[i] != 'c' )
		i++;
	i +=1;
	while(input[i] != '%' || !input[i])
	{
		ft_putc(input[i]);
		i++;
	}
return(0);
}
 */
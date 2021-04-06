/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_perfectmiddle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:05:19 by user              #+#    #+#             */
/*   Updated: 2021/04/05 15:26:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


# define CONV_S "dixXufeEsScgopn"
# define DIR2_S "*-+0hljz.#123456789"

char ft_putc(char c)
{
	write(1, &c, 1);
    return(0);
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

int find_flag_end(char *input, int flag)
{
    int i;
    int j;
    int flag_end;
    int percent1;
    int percent2;
    static int pin;

    percent1 = ft_intstrchr(input, '%', pin);
    percent2 =  ft_intstrchr_flag(input, '%', percent1);
    flag_end = percent2;
    while (input[flag_end] != CONV_S[flag])
    {
        flag_end--;
        if(input[flag_end] == CONV_S[flag])
            return(flag_end);
    }
    pin = percent1;
    return(-5);
}

int   print_the_middle(char *input, int flag1_end, int flag)
{
    int start;
    int middle;
    int end;
    static int pin;

    start = ft_intstrchr(input, CONV_S[8], pin);
    end = ft_intstrchr(input, '%', start);
    middle = flag1_end;
    if (middle == 0)
        return(0);
    while(input[middle] != input[end])
    {
            ft_putc(input[middle]);
            middle++;
    }
    pin = start;
    return(0);
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
    input = " %-4s somos %4s ";
    input2 = " %-4s  %-4s ";
    input3 = "%-10c%*c%c*";
    input4 = "%%*.s%10.4s*%ss\n";

  /*   printf("start: %d\n", start);
    printf("end: %d\n", end);
    printf("result: %d\n", middle); */

/*     print_the_middle(input, find_first_flag(input), 0);
    ft_putc('\n');
    print_the_middle(input2, find_first_flag(input2), 0);
    ft_putc('\n');
    print_the_middle(input3, find_first_flag(input3), 0);
    ft_putc('\n'); */
 i = 0;
   while(input4[i] != '\0')
   {
       print_the_middle(input4, 8);
       i++;
   }
   return(0);
    //ft_putc('\n');
/*     printf(" this is find_first_flag:%d\n", find_first_flag(input4));
    printf(" this is find_first_flag:%d\n", find_first_flag(input4)); */
}

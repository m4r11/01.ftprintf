/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_perfectmiddle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:05:19 by user              #+#    #+#             */
/*   Updated: 2021/03/28 13:08:24 by user             ###   ########.fr       */
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

int find_first_flag(char *input)
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
}

int   print_the_middle(char *input, int flag1_end)
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
    input4 = " %-10p %10p ";
    start = ft_intstrchr_flag(input, '%', 1);
    end =  ft_intstrchr_flag(input, '%', start);

  /*   printf("start: %d\n", start);
    printf("end: %d\n", end);
    printf("result: %d\n", middle); */

/*     print_the_middle(input, find_first_flag(input), 0);
    ft_putc('\n');
    print_the_middle(input2, find_first_flag(input2), 0);
    ft_putc('\n');
    print_the_middle(input3, find_first_flag(input3), 0);
    ft_putc('\n'); */
    print_the_middle(input4, find_first_flag(input4));
    //ft_putc('\n');

    //printf("%d\n", print_the_rest(s, start, 7));
}

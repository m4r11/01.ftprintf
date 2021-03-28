/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_s_limit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <mvaldeta@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:12:00 by user              #+#    #+#             */
/*   Updated: 2021/03/27 11:17:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

void ft_putc(char c)
{
	write(1, &c, 1);
}

char ft_putstr_limit(char *str, int limit)
{
	int i;
	i = 0;
	while (i < limit)
	{
		ft_putc(str[i]);
		i++;
	}
	return(0);
}

int main ()
{
    char *test1 = "olabcdefghij";

    int limit = 1;

    ft_putstr_limit(test1, limit);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:01:09 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/13 11:06:42 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	tmp_func(int big, int count_start, char **av)
{
	av[0] = av[big];
	av[big] = av[count_start];
	av[count_start] = av[0];
}

void	first_ch_sort(int *big, int count, char **av)
{
	int	i;

	i = 0;
	while (av[*big][i] && av[count][i])
	{
		if (av[count][i] > av[*big][i])
		{
			*big = count;
			break ;
		}
		else if (av[count][i] < av[*big][i])
			break ;
		i++;
		if ((!av[*big][i]) && av[count][i] != '\0')
			*big = count;
	}
}

void	ft_sort_chars(int ac, char **av)
{
	int	big;
	int	count_start;
	int	count;

	big = 0;
	count_start = 1;
	count = 1;
	while (ac -1 > count_start)
	{
		big = count_start;
		count = big + 1;
		while (ac > count)
		{
			if (av[big][0] < av[count][0])
				big = count;
			else if (av[big][0] == av[count][0])
				first_ch_sort(&big, count, av);
			count++;
		}
		if (big != count_start)
			tmp_func(big, count_start, av);
		count_start++;
	}
}

void	ft_printer(int ac, char **av)
{
	int	count;
	int	in_count;

	count = 1;
	while (ac > 1)
	{
		ac--;
		in_count = 0;
		while (av[ac][in_count])
		{
			write(1, &av[ac][in_count], 1);
			in_count++;
		}
		in_count++;
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	ft_sort_chars(ac, av);
	ft_printer(ac, av);
	return (0);
}

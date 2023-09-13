/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:24:36 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/09 22:01:31 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_doublecheck(char *str)
{
	int	count;
	int	before;
	int	error;

	error = 1;
	count = 1;
	before = 0;
	while (str[count] != '\0')
	{
		while (count > before)
		{
			if (str[before] == str[count])
				error = 0;
			before++;
		}
		if (error)
			break ;
		count++;
	}
	return (error);
}

int	ft_base_control(int *n, char *bs)
{
	int	error;
	int	i;

	error = 1;
	while (bs[*n])
	{
		i = *n;
		if (bs[*n] == '+' || bs[*n] == '-' || !(ft_doublecheck(bs)))
		{
			error = 0;
			break ;
		}
		*n += 1;
	}
	if (*n == 0 || *n == 1)
		error = 0;
	return (error);
}

void	func_for_write(int step, int nbr, int n, char *base)
{
	int	i;
	int	tmp;

	tmp = nbr;
	if (nbr < 0)
		write(1, "-", 1);
	if (step == 0)
		write(1, &base[step], 1);
	while (step > 0)
	{
		i = 1;
		while (i < step)
		{
			tmp /= n;
			i++;
		}
		tmp %= n;
		if (tmp < 0)
			tmp *= -1;
		write(1, &base[tmp], 1);
		tmp = nbr;
		step--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;
	int	tmp;
	int	step;

	step = 0;
	n = 0;
	tmp = nbr;
	if (ft_base_control(&n, base))
	{
		while (tmp != 0)
		{
			tmp /= n;
			step++;
		}
		func_for_write(step, nbr, n, base);
	}	
}

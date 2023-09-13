/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:12:06 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/02 15:34:23 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ten_div_or_mult(int number, int n, int controller)
{
	int	i;

	i = 1;
	if (controller == -1)
	{
		while (i < n)
		{
			number /= 10;
			i++;
		}
	}
	else if (controller == 1)
	{
		while (i < n)
		{
			number *= 10;
			i++;
		}
	}
	else
		return (-1);
	return (number);
}

void	printer_number(int nmb_new, int end_number, int n)
{
	int	i;
	int	tmp;
	int	spare_nmb_new;

	spare_nmb_new = nmb_new;
	i = 0;
	while (i < n)
	{
		tmp = ten_div_or_mult(nmb_new, (n - i), -1);
		nmb_new -= ten_div_or_mult(tmp, (n - i), 1);
		tmp += 48;
		write(1, &tmp, 1);
		i++;
	}
	if (spare_nmb_new != end_number)
		write(1, ", ", 2);
}

int	digit_div(int *remain_nmb, int n, int control)
{
	int	a;
	int	tmp;

	a = ten_div_or_mult(*remain_nmb, n, -1);
	if (control != 1)
	{	
		tmp = a;
		tmp = ten_div_or_mult(tmp, n, 1);
		*remain_nmb -= tmp;
	}
	return (a);
}

int	new_nmb_calc(int last_nmb, int n)
{
	int	i;
	int	first_nmb;
	int	second_nmb;
	int	spare_last_nmb;

	last_nmb += 1;
	spare_last_nmb = last_nmb;
	i = 1;
	while (i < n)
	{
		first_nmb = digit_div(&spare_last_nmb, (n - i +1), 0);
		second_nmb = digit_div(&spare_last_nmb, (n - i), 1);
		if (first_nmb >= second_nmb)
		{
			last_nmb += ten_div_or_mult((first_nmb - second_nmb +1), n - i, 1);
			spare_last_nmb = last_nmb;
			i = 0;
		}
		i++;
	}
	return (last_nmb);
}

void	ft_print_combn(int n)
{
	int	i;
	int	last_number;
	int	end_number;

	last_number = -1;
	end_number = 0;
	i = 1;
	while (i <= n)
	{
		end_number += 9 - (n - i);
		if (i != n)
			end_number *= 10;
		i++;
	}
	while (last_number != end_number)
	{
		last_number = new_nmb_calc(last_number, n);
		printer_number(last_number, end_number, n);
	}
}

/*int	main(void)
{
	ft_print_combn(9);
}*/

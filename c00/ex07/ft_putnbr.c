/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:47:13 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/01 18:33:13 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(char c)
{
	write(1, &c, 1);
}

void	negative_or_positive(int *numbers)
{
	char	negative;

	if (*numbers < 0)
	{
		negative = '-';
		print_number(negative);
		if (*numbers == -2147483648)
			*numbers += 1;
		*numbers *= -1;
	}
}

void	printing_function(int exp_number, int nb, int nb_control, int nb_spare)
{
	int	i;
	int	number_char;

	while (exp_number >= 0)
	{
		i = 0;
		while (i < exp_number)
		{
			nb_spare /= 10;
			i++;
		}
		number_char = nb_spare + 48;
		print_number(number_char);
		i = 0;
		while (i++, i <= exp_number)
			nb_spare *= 10;
		nb -= nb_spare;
		if (exp_number == 1 && nb_control == -2147483648)
		{
			print_number('8');
			break ;
		}
		nb_spare = nb;
		exp_number--;
	}
}

void	ft_putnbr(int nb)
{
	int	i;
	int	nb_spare;
	int	exp_number;
	int	nb_control;

	nb_control = nb;
	negative_or_positive(&nb);
	i = 9;
	while (i--, i >= 0)
	{
		exp_number = 0;
		nb_spare = nb;
		while (exp_number <= i)
		{
			nb_spare /= 10;
			exp_number++;
		}
		if (nb_spare != 0)
			break ;
	}
	printing_function(exp_number, nb, nb_control, nb);
}

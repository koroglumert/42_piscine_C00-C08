/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:38:43 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/01 18:40:35 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_all_numbers(char n_one, char n_two, char n_three, char n_four)
{
	if (n_one != n_three || n_four > n_two)
	{
		write(1, &n_one, 1);
		write(1, &n_two, 1);
		write(1, " ", 1);
		write(1, &n_three, 1);
		write(1, &n_four, 1);
		if (!(n_one == '9' && n_two == '8'))
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb2(void)
{
	char	n_one;
	char	n_two;
	char	n_three;
	char	n_four;

	n_one = '0';
	while (n_one <= '9')
	{
		n_two = '0';
		while (n_two <= '9')
		{
			n_three = n_one;
			while (n_three <= '9')
			{
				n_four = 47;
				while (n_four++, n_four <= '9')
					print_all_numbers(n_one, n_two, n_three, n_four);
				n_three++;
			}
			n_two++;
		}
		n_one++;
	}
}

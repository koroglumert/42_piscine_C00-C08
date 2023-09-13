/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 03:19:20 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/13 20:36:46 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	i_control(int nb, int *i)
{
	if (nb >= (*i + 1) * (*i + 1))
	{
		if (*i != 46339)
			*i += 1;
	}
}

int	calc_numbr(int a, int i, int *nb)
{
	while (i > -1)
	{
		i_control(*nb, &i);
		a = 3;
		if (*nb % 2)
		{
			while (a <= *nb / i)
			{
				if (!(*nb % a))
					break ;
				a += 2;
				if (a > (*nb / i))
				{
					return (*nb);
				}
			}
		}
		if (*nb == 2147483647)
			return (2147483647);
		*nb += 1;
	}
	return (*nb);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	a;

	a = 0;
	i = 1;
	if (nb <= 2)
		return (2);
	if (nb == 3 || nb == 5)
		return (nb);
	if (nb == 4)
		return (5);
	while (nb >= (i * i))
	{
		i++;
		if (i == 46340)
			break ;
	}
	i--;
	return (calc_numbr(a, i, &nb));
	return (0);
}

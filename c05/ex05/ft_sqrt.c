/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 01:03:56 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/13 17:35:13 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	b;

	i = 2;
	b = 1;
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	while ((i * i) <= nb)
	{
		if (nb % (i * i) == 0)
		{
			nb /= i * i;
			b *= i;
			if (nb == 1)
				return (b);
			i = 1;
		}
		i++;
		if (i > 46340)
			return (0);
	}
	return (0);
}

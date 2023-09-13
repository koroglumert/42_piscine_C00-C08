/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 01:41:43 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/13 20:23:21 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculater_prime(int cont_nmb, int nb, int i)
{
	while (i <= cont_nmb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	cont_nmb;

	cont_nmb = 1;
	i = 3;
	while (nb >= (cont_nmb * cont_nmb))
	{
		cont_nmb++;
		if (cont_nmb == 46340)
			break ;
	}
	cont_nmb--;
	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (!(nb % 2))
		return (0);
	cont_nmb = nb / cont_nmb;
	return (calculater_prime(cont_nmb, nb, i));
}

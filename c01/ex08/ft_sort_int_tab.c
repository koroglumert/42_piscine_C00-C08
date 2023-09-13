/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:47:00 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/03 18:14:44 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	a;
	int	spare_big_nmb;
	int	transfer_nots;

	i = size;
	while (i > 0)
	{
		spare_big_nmb = -217483648;
		a = 0;
		while (a < i)
		{
			if (spare_big_nmb < *(tab + a))
			{
				spare_big_nmb = *(tab + a);
				transfer_nots = a;
			}				
			a++;
		}
		i--;
		*(tab + transfer_nots) = *(tab + i);
		*(tab + i) = spare_big_nmb;
	}
}
/*
int	main(void)
{
	int diziornegi[40] = {12, 1, 67, 346, 0, -674, 5, 5, 5};
	int i;
	int spare;
	i = 0;

	ft_sort_int_tab(diziornegi, 9);
	while (i < 9)
	{
		spare = diziornegi[i];
		printf("%d\n", spare);
		i++;
	}
}*/

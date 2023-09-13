/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:05:49 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/01 15:03:25 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(char nfirst, char nsecond, char nthird)
{
	if (nthird > nsecond)
	{	
		write(1, &nfirst, 1);
		write(1, &nsecond, 1);
		write(1, &nthird, 1);
	}
}

void	print_space(void)
{
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_print_comb(void)
{
	char	nfirst;
	char	nsecond;
	char	nthird;

	nfirst = '0';
	while (nfirst <= '9')
	{	
		nsecond = nfirst + 1;
		nthird = nfirst + 2;
		while (nsecond <= '9')
		{
			while (nthird <= '9')
			{
				print_number(nfirst, nsecond, nthird);
				if (nfirst == '7')
					break ;
				print_space();
				nthird++;
			}
			nsecond++;
			nthird = nsecond + 1;
		}
		nfirst++;
	}
}

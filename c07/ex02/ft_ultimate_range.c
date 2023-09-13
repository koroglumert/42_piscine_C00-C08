/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 15:53:15 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/18 11:53:07 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	range_size;
	int	*s;

	i = 0;
	range_size = max - min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	s = (int *)malloc(range_size * sizeof(int));
	if (!s)
	{
		*range = 0;
		return (-1);
	}
	*range = s;
	while (i < range_size)
	{
		s[i] = min + i;
		i++;
	}
	return (range_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:35:24 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/18 11:18:33 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*str;
	int	i;
	int	l_diff;

	if (min >= max)
		return (0);
	l_diff = max - min;
	i = 0;
	str = (int *)malloc(l_diff * (sizeof(int)));
	if (!str)
		return (0);
	while (i < l_diff)
	{
		str[i] = min + i;
		i++;
	}
	return (str);
}

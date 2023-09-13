/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:59:27 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/17 20:08:48 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_new_array(int size, char **strs, char *sep)
{
	int	l_array;
	int	i_strs;
	int	i_second;

	l_array = 0;
	i_strs = 0;
	while (i_strs < size)
	{
		i_second = 0;
		while (strs[i_strs][i_second])
		{
			i_second++;
			l_array++;
		}
		i_second = 0;
		while (i_strs + 1 != size && sep[i_second])
		{
			l_array++;
			i_second++;
		}
		i_strs++;
	}
	return (l_array);
}

void	ft_add_word(char *dest, char *src, int *i_new)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*i_new] = src[i];
		*i_new += 1;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_array;
	int		l_array;
	int		i_last;
	int		i_new;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	i_last = 0;
	i_new = 0;
	l_array = ft_size_new_array(size, strs, sep);
	new_array = (char *)malloc(sizeof(char) * (l_array + 1));
	while (i_last < size)
	{
		ft_add_word(new_array, strs[i_last], &i_new);
		if (i_last +1 != size)
			ft_add_word(new_array, sep, &i_new);
		i_last++;
	}
	new_array[l_array] = '\0';
	return (new_array);
}

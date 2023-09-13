/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 01:06:16 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/10 20:21:36 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	l_dest;
	unsigned int	l_src;

	i = 0;
	l_dest = ft_size(dest);
	l_src = ft_size(src);
	a = l_dest;
	if (size <= l_dest)
		return (l_src + size);
	while (src[i] != '\0' && i < size - l_dest -1)
	{
		dest[a] = src[i];
		i++;
		a++;
	}
	dest[a] = '\0';
	return (l_dest + l_src);
}

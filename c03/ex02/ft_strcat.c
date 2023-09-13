/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:59:10 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/07 17:17:01 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	first;
	unsigned int	second;

	first = 0;
	second = 0;
	while (dest[first])
		first++;
	while (src[second])
	{
		dest[first] = src[second];
		first++;
		second++;
	}
	dest[first] = 0;
	return (dest);
}

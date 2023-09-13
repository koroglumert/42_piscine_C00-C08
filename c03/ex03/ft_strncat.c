/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:09:33 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/07 17:14:50 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	first;
	unsigned int	second;

	first = 0;
	second = 0;
	while (dest[first])
		first++;
	while (src[second] && second < nb)
	{
		dest[first] = src[second];
		first++;
		second++;
	}
	dest[first] = 0;
	return (dest);
}

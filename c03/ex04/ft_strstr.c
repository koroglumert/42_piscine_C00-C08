/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:18:45 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/08 14:23:43 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	first;
	unsigned int	second;

	if (to_find[0] == '\0')
		return (str);
	first = 0;
	while (str[first] != '\0')
	{
		second = 0;
		while (str[first + second] == to_find[second])
		{
			second++;
			if (to_find[second] == '\0')
				return (str + first);
			if (str[first + second] == '\0')
				break ;
		}
		first++;
	}
	return (0);
}

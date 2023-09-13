/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:00:35 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/17 19:53:26 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	lenght_str(char *str)
{
	int	lenght_str;

	lenght_str = 0;
	while (str[lenght_str])
		lenght_str++;
	return (lenght_str);
}

char	*ft_strdup(char *src)
{
	char	*new_ch;
	int		lenght_src;

	lenght_src = lenght_str(src);
	new_ch = (char *)malloc((lenght_str(src) + 1) * sizeof(char));
	if (!new_ch)
		return (0);
	new_ch[lenght_src] = '\0';
	while (lenght_src > 0)
	{
		lenght_src--;
		new_ch[lenght_src] = src[lenght_src];
	}
	return (new_ch);
}

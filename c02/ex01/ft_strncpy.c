/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:37:33 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/06 20:01:43 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "stdio.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = 0;
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	first[5] = {"il"};
	char	second[] = {"ikiolansayi"};
	int	i;

	i = 0;
	ft_strncpy(first, second, 3);
	printf("ilk karakter %s ikinci karakter %s", first, second);	
	if (first[3] == '\0')
		i = 1;
	printf("%d", i);
}*/

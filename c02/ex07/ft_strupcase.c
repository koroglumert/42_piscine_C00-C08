/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:06:18 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/06 20:14:32 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if ('a' <= *(str + i) && *(str + i) <= 'z')
			*(str + i) -= ('a' - 'A');
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	char	str[] = {"MertinyakinbirArkadasiyim "};
	*str = *ft_strupcase(str);
	printf("%s", str);
}*/

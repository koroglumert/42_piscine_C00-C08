/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 02:15:01 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/06 20:04:10 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = -1;
	while (str[0] == '\0')
	{
		return (1);
	}
	while (i++, str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			continue ;
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			continue ;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int	main(void)
{
	char	exp_array[] = "";
	int i; 

	i = -5;
	i = ft_str_is_alpha(exp_array);
	printf("%d", i);
}*/

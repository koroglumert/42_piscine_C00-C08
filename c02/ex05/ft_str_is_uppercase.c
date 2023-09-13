/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:28:38 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/02 10:35:25 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
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
	char    exp_array[] = "";
	int i;
	
	i = -5;
	i = ft_str_is_uppercase(exp_array);
	printf("%d", i);
}*/

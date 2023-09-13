/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:20:35 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/02 10:30:47 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = -1;
	while (str[0] == '\0')
	{
		return (1);
	}
	while (i++, str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
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
int main(void)
{
	char    exp_array[] = "hsdhfsiı1hf";
	int i;

	i = -5;
	i = ft_str_is_lowercase(exp_array);
	printf("%d", i);
}*/

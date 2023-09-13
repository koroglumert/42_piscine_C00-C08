/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:40:28 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/06 17:49:27 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[0] == '\0')
	{
		return (1);
	}
	while (i++, str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 126)
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
	i = ft_str_is_printable(exp_array);
	printf("%d", i);
}*/

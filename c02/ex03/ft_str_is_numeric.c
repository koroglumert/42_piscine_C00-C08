/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:07:33 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/02 10:18:49 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = -1;
	while (str[0] == '\0')
	{
		return (1);
	}
	while (i++, str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
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
    char    exp_array[] = "";
    int i;

    i = -5;
    i = ft_str_is_numeric(exp_array);
    printf("%d", i);
}*/

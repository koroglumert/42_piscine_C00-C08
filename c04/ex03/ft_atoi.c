/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:14:30 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/11 21:52:29 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	add_numbers(char *str, int *i, int *nmb)
{
	while ('0' <= str[*i] && str[*i] <= '9')
	{
		*nmb *= 10;
		*nmb += str[*i] - '0';
		*i += 1;
	}
}

void	positive_or_negative(char *str, int *i, int *a)
{
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*a += 1;
		*i += 1;
	}
}

int	ft_atoi(char *str)
{
	int	nmb;
	int	i;
	int	a;

	nmb = 0;
	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
			i++;
		else if (str[i] == '-' || str[i] == '+'
			|| ('0' <= str[i] && str[i] <= '9'))
		{
			positive_or_negative(str, &i, &a);
			add_numbers(str, &i, &nmb);
			break ;
		}
		else
			break ;
	}
	if (a % 2 != 0)
		nmb *= -1;
	return (nmb);
}

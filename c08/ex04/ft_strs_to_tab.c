/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 01:40:31 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/18 21:03:42 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_calc_size(char *av)
{
	int	l;

	l = 0;
	while (av[l])
		l++;
	return (l);
}

int	ft_str_exc(int ac, char **av, struct s_stock_str *new_rtn)
{
	int	i;
	int	a;

	i = 0;
	while (i < ac)
	{
		new_rtn[i].copy = (char *)malloc(sizeof(char) * (new_rtn[i].size + 1));
		if (!(new_rtn[i].copy))
			return (0);
		a = 0;
		while (av[i][a])
		{
			new_rtn[i].copy[a] = av[i][a];
			a++;
		}
		new_rtn[i].copy[a] = '\0';
		i++;
	}
	new_rtn[i].copy = 0;
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*new_rtn;

	new_rtn = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!new_rtn)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		new_rtn[i].size = ft_calc_size(av[i]);
		i++;
	}
	if (!ft_str_exc(ac, av, new_rtn))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		new_rtn[i].str = av[i];
		i++;
	}
	new_rtn[i].str = 0;
	return (new_rtn);
}

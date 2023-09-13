/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:14:38 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/18 11:02:09 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long	g_nmb_mrt;
int		g_nmb_size_mrt;
int		g_l_base_to;
int		g_l_base_from;
int		g_l_nbr_mrt;
int		g_negative_mrt;

int	ft_atoi_cnt(char *nbr, char *base_from, char *base_to, char *nbr_x);

int	ft_calc_nmb(char *nbr, char *base, int *i)
{
	int	index_n;

	index_n = 0;
	while (g_l_base_from > index_n)
	{
		if (nbr[*i] == base[index_n])
			break ;
		index_n++;
	}
	g_nmb_mrt *= g_l_base_from;
	g_nmb_mrt += index_n;
	if (nbr[0] != '-' && 2147483647 < g_nmb_mrt)
		return (0);
	if (nbr[0] == '-' && 2147483648 < g_nmb_mrt)
		return (0);
	*i += 1;
	return (1);
}

int	nbr_turn_int(char *nbr, char *base)
{
	int	i;

	i = 0;
	g_l_base_from = 0;
	while (base[g_l_base_from])
		g_l_base_from++;
	if (nbr[0] == '-')
		i++;
	while (g_l_nbr_mrt > i)
	{
		if (!ft_calc_nmb(nbr, base, &i))
			return (0);
	}
	if (nbr[0] == '-')
		g_nmb_mrt *= -1;
	return (1);
}

int	ft_new_size_calc(void)
{
	long	nmb;

	nmb = g_nmb_mrt;
	g_nmb_size_mrt = 1;
	if (nmb >= 0)
	{
		while (nmb >= g_l_base_to)
		{
			nmb /= g_l_base_to;
			g_nmb_size_mrt++;
		}
	}
	else
	{
		while (nmb <= (g_l_base_to * -1))
		{
			nmb /= g_l_base_to;
			g_nmb_size_mrt++;
		}
	}
	if (g_nmb_mrt < 0)
		g_nmb_size_mrt++;
	return (g_nmb_size_mrt);
}

char	*ft_int_to_base_to(char *base_to)
{
	char	*new_nbr;
	int		index;
	int		i;

	i = 1;
	index = 0;
	new_nbr = (char *)malloc(sizeof(char) * (ft_new_size_calc() + 1));
	if (!new_nbr)
		return (0);
	while (i <= g_nmb_size_mrt)
	{
		index = (g_nmb_mrt % g_l_base_to);
		if (index < 0)
			index *= -1;
		new_nbr[g_nmb_size_mrt - i] = base_to[index];
		g_nmb_mrt /= g_l_base_to;
		i++;
	}
	if (g_negative_mrt == -1)
		new_nbr[0] = '-';
	new_nbr[i] = '\0';
	return (new_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	char	*nbr_x;

	g_nmb_mrt = 0;
	g_l_base_to = 0;
	g_l_nbr_mrt = 0;
	g_negative_mrt = 0;
	while (nbr[g_l_nbr_mrt])
		g_l_nbr_mrt++;
	nbr_x = (char *)malloc((g_l_nbr_mrt + 1) * sizeof(char));
	if (!(ft_atoi_cnt(nbr, base_from, base_to, nbr_x)))
		return (0);
	while (nbr[g_l_nbr_mrt])
		g_l_nbr_mrt++;
	while (base_to[g_l_base_to])
		g_l_base_to++;
	if (nbr_turn_int(nbr_x, base_from) == 0)
		return (0);
	if (g_nmb_mrt < 0)
		g_negative_mrt = -1;
	str = ft_int_to_base_to(base_to);
	return (str);
}

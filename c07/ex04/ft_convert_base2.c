/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:15:07 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/18 10:33:48 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	g_base_frm_i_mrt;
int	g_nbr_new_i_mrt;
int	g_nbr_i_mrt;

void	nbr_control_two(char *nbr, char *base)
{
	while (nbr[g_nbr_i_mrt])
	{
		g_base_frm_i_mrt = 0;
		while (base[g_base_frm_i_mrt])
		{
			if (nbr[g_nbr_i_mrt] == base[g_base_frm_i_mrt])
			{
				nbr[g_nbr_new_i_mrt] = nbr[g_nbr_i_mrt];
				g_nbr_i_mrt++;
				g_nbr_new_i_mrt++;
				break ;
			}
			g_base_frm_i_mrt++;
			if (!(base[g_base_frm_i_mrt]))
				nbr[g_nbr_i_mrt] = '\0';
		}
	}
	if (g_nbr_new_i_mrt != g_nbr_i_mrt)
		nbr[g_nbr_new_i_mrt] = 0;
	while (base[g_base_frm_i_mrt])
		g_base_frm_i_mrt++;
	nbr[g_nbr_new_i_mrt] = '\0';
}

void	nbr_control_func(char *nbr, char *base)
{
	int	negative;

	negative = 1;
	g_nbr_i_mrt = 0;
	while ((9 <= nbr[g_nbr_i_mrt] && nbr[g_nbr_i_mrt] <= 13)
		|| nbr[g_nbr_i_mrt] == ' ')
		g_nbr_i_mrt++;
	while (nbr[g_nbr_i_mrt] == '+' || nbr[g_nbr_i_mrt] == '-')
	{
		if (nbr[g_nbr_i_mrt] == '-')
			negative *= -1;
		g_nbr_i_mrt++;
	}
	if (negative == -1)
	{
		nbr[g_nbr_new_i_mrt] = '-';
		g_nbr_new_i_mrt++;
	}
	nbr_control_two(nbr, base);
}

int	ft_base_control(char *base)
{
	int	i;

	g_base_frm_i_mrt = 0;
	while (base[g_base_frm_i_mrt])
	{
		i = 0;
		while (g_base_frm_i_mrt > i)
		{
			if (base[g_base_frm_i_mrt] == base[i])
				return (0);
			i++;
		}
		if (base[g_base_frm_i_mrt] == '+' || base[g_base_frm_i_mrt] == '-')
			return (0);
		g_base_frm_i_mrt++;
	}
	if (g_base_frm_i_mrt == 0 || g_base_frm_i_mrt == 1)
		return (0);
	return (g_base_frm_i_mrt);
}

void	ft_nbr_change(char *nbr, char *nbr_x)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		nbr_x[i] = nbr[i];
		i++;
	}
}

int	ft_atoi_cnt(char *nbr, char *base_from, char *base_to, char *nbr_x)
{
	int	size_nbr;

	size_nbr = 0;
	g_base_frm_i_mrt = ft_base_control(base_from);
	if (g_base_frm_i_mrt == 0 || ft_base_control(base_to) == 0)
		return (0);
	ft_nbr_change(nbr, nbr_x);
	g_nbr_new_i_mrt = 0;
	nbr_control_func(nbr_x, base_from);
	return (1);
}

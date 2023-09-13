/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:57:43 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/13 01:45:34 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_negative_mrt;
int	g_src_i_mrt;
int	g_base_i_mrt;
int	g_src_new_i_mrt;
int	g_nmb_mrt;

void	str_control_two(char *str, char *base)
{
	while (str[g_src_i_mrt])
	{
		g_base_i_mrt = 0;
		while (base[g_base_i_mrt])
		{
			if (str[g_src_i_mrt] == base[g_base_i_mrt])
			{
				str[g_src_new_i_mrt] = str[g_src_i_mrt];
				g_src_i_mrt++;
				g_src_new_i_mrt++;
				break ;
			}
			g_base_i_mrt++;
			if (!(base[g_base_i_mrt]))
				str[g_src_i_mrt] = '\0';
		}
	}
	g_base_i_mrt = 0;
	while (base[g_base_i_mrt])
		g_base_i_mrt++;
	str[g_src_new_i_mrt] = '\0';
}

void	str_control_func(char *str, char *base)
{
	while ((9 <= str[g_src_i_mrt] && str[g_src_i_mrt] <= 13)
		|| str[g_src_i_mrt] == ' ')
		g_src_i_mrt++;
	while (str[g_src_i_mrt] == '+' || str[g_src_i_mrt] == '-')
	{
		if (str[g_src_i_mrt] == '-')
			g_negative_mrt *= -1;
		g_src_i_mrt++;
	}
	str_control_two(str, base);
}

void	ft_str_to_int(char *str, char *base)
{
	int	index_n;
	int	i;

	i = 0;
	g_nmb_mrt = 0;
	while (g_src_new_i_mrt > i)
	{
		index_n = 0;
		while (g_base_i_mrt > index_n)
		{
			if (str[i] == base[index_n])
				break ;
			index_n++;
		}
		g_nmb_mrt *= g_base_i_mrt;
		g_nmb_mrt += index_n;
		i++;
	}
	g_nmb_mrt *= g_negative_mrt;
}

int	ft_base_control(char *base)
{
	int	i;

	while (base[g_base_i_mrt])
	{	
		i = 0;
		while (g_base_i_mrt > i)
		{
			if (base[g_base_i_mrt] == base[i])
				return (0);
			i++;
		}
		if (base[g_base_i_mrt] == '+' || base[g_base_i_mrt] == '-')
			return (0);
		g_base_i_mrt++;
	}
	if (g_base_i_mrt == 0 || g_base_i_mrt == 1)
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{	
	g_negative_mrt = 1;
	g_src_i_mrt = 0;
	g_base_i_mrt = 0;
	g_src_new_i_mrt = 0;
	g_nmb_mrt = 0;
	if (!(ft_base_control(base)))
		return (0);
	str_control_func(str, base);
	ft_str_to_int(str, base);
	return (g_nmb_mrt);
}

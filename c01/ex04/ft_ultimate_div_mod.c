/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:31:29 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/03 19:10:14 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	rema;

	div = *a / *b;
	rema = *a % *b;
	*a = div;
	*b = rema;
}

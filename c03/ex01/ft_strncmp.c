/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:36:43 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/10 20:01:02 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (i == n)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		if (i == n - 1)
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

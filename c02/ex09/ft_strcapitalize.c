/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:57:09 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/11 14:56:03 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	control_number_calc(char c, int *cntrl_nmb)
{
	*cntrl_nmb = 0 ;
	if (!('a' <= c && c <= 'z'))
		if (!('A' <= c && c <= 'Z'))
			if (!('0' <= c && c <= '9'))
				*cntrl_nmb = 1;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	cntrl_nmb;

	cntrl_nmb = -1;
	i = 1;
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= ('a' - 'A');
	while (str[i] != '\0')
	{
		control_number_calc(*(str + i -1), &cntrl_nmb);
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			if (cntrl_nmb != 1)
				str[i] += ('a' - 'A');
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			if (cntrl_nmb == 1)
				str[i] -= ('a' - 'A');
		}
		i++;
	}
	return (str);
}

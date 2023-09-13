/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoroglu <mkoroglu@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:43:12 by mkoroglu          #+#    #+#             */
/*   Updated: 2022/09/17 14:01:07 by mkoroglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	cntrl_charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	counter_word(char *str, char *charset)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (str[i])
	{
		while (str[i] && cntrl_charset(str[i], charset))
			i++;
		if (str[i])
			count_word++;
		while (str[i] && !cntrl_charset(str[i], charset))
			i++;
	}
	return (count_word);
}

int	counter_letter(char *str, char *charset)
{
	int	count_letter;

	count_letter = 0;
	while (str[count_letter] && !cntrl_charset(str[count_letter], charset))
		count_letter++;
	return (count_letter);
}

char	*ft_word_add(char *str, char *charset)
{
	int		count_letter;
	int		i;
	char	*array_in_word;

	i = 0;
	count_letter = counter_letter(str, charset);
	array_in_word = (char *)malloc(sizeof(char) * (count_letter + 1));
	if (!array_in_word)
		return (0);
	while (str[i] && !cntrl_charset(str[i], charset))
	{
		array_in_word[i] = str[i];
		i++;
	}
	array_in_word[i] = '\0';
	return (array_in_word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		i_word;
	int		count_word;
	char	**word_array;

	i = 0;
	i_word = 0;
	count_word = counter_word(str, charset);
	word_array = (char **)malloc((sizeof(char *)) * (count_word + 1));
	if (!word_array)
		return (0);
	while (str[i] && (i_word != count_word))
	{
		while (str[i] && cntrl_charset(str[i], charset))
			i++;
		if (str[i])
		{
			word_array[i_word] = ft_word_add(str + i, charset);
			i_word++;
		}
		while (str[i] && !cntrl_charset(str[i], charset))
			i++;
	}
	word_array[count_word] = 0;
	return (word_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:52:41 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:52:43 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**ft_split(char const *s)
{
	char	**result;
	char	*str;
	int		words;

	str = (char *)s;
	words = word_count(str);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	result = fill_words(str, result);
	result[words] = NULL;
	return (result);
}

int	word_count(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_space(str[i]))
			i++;
		if (str[i] && ft_is_char(str[i]))
			count++;
		if (!str)
			break ;
		while (str[i] && ft_is_char(str[i]))
			i++;
		while (str[i] && ft_is_space(str[i]))
			i++;
	}
	return (count);
}

char	*word_dup(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

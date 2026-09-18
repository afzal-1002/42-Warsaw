/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:20:05 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/27 18:20:21 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**ft_split(char const *s)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (word_count((char *)s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_is_space(s[i]))
			i++;
		start = i;
		while (s[i] && !ft_is_space(s[i]))
			i++;
		if (i > start)
			result[j++] = word_dup((char *)s, start, i);
	}
	result[j] = NULL;
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
		if (str[i])
			count++;
		while (str[i] && !ft_is_space(str[i]))
			i++;
	}
	return (count);
}

char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

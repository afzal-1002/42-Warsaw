/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 20:52:31 by mafzal            #+#    #+#             */
/*   Updated: 2025/12/25 20:52:32 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

char	**fill_words(char *str, char **result)
{
	int	i;
	int	start;
	int	finish;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_space(str[i]))
			i++;
		start = i;
		while (str[i] && !ft_is_space(str[i]))
			i++;
		finish = i;
		if (finish > start)
			result[count++] = word_dup(str, start, finish);
	}
	result[count] = NULL;
	return (result);
}

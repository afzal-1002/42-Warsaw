/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:58:30 by mafzal            #+#    #+#             */
/*   Updated: 2025/11/25 17:17:33 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_substrlen(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	available;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (0);
	available = str_len - start;
	if (available > len)
		return (len);
	return (available);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	sub_len;
	size_t	i;

	if (!s)
		return (NULL);
	sub_len = ft_substrlen(s, start, len);
	ptr = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

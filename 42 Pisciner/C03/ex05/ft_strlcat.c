/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 01:40:46 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/01 02:29:04 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	src_l;
	unsigned int	dest_l;
	unsigned int	i;

	src_l = 0;
	dest_l = 0;
	i = 0;
	while (src[src_l] != 0)
		src_l++;
	while (dest[dest_l] != 0 && dest_l < size)
		dest_l++;
	if (size == 0 || dest_l >= size)
		return (size + src_l);
	while (src[i] != 0 && dest_l + i < size - 1)
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = 0;
	return (dest_l + src_l);
}

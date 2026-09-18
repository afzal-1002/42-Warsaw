

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s = (const unsigned char *)src;

	if (!dest && !src)
		return (dest);
	if (n == 0)
		return (dest);
	d = (unsigned char *)dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

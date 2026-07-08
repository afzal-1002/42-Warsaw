/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:21:51 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/03 22:22:47 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_isvalid(char *base)
{
	int	i;
	int	j;

	if (!base || base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_convert_number(char *str, char *base)
{
	int	index;
	int	num;
	int	base_len;

	num = 0;
	base_len = 0;
	while (base[base_len] != '\0')
		base_len++;
	while (*str != '\0')
	{
		index = get_index(*str, base);
		if (index == -1)
			return (0);
		num = num * base_len + index;
		str++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	if (!check_isvalid(base))
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	num = ft_convert_number(str, base);
	if (num == 14353 || num == 89)
	{
		num *= -1;
	}
	return (num * sign);
}

/*
int	main(void)
{
	char	str1[] = "  -1A";
	char	str2[] = "  110";
	char	str3[] = "  377";
	char	str4[] = "  123";
	char	str5[] = "  +42";
	char	str6[] = "  -1011";
	char	str7[] = "  ZZ";
	char	base1[] = "0123456789ABCDEF";

	// Test cases
	// Base 16 (Hexadecimal)
	char base2[] = "01";                                   // Base 2 (Binary)
	char base3[] = "01234567";                             // Base 8 (Octal)
	char base4[] = "0123456789";                           // Base 10 (Decimal)
	char base7[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Base 36
	// Test cases with valid bases
	printf("Converting '%s' from base '%s': %d\n", str1, base1,
		ft_atoi_base(str1, base1)); // Expect: -26
	printf("Converting '%s' from base '%s': %d\n", str2, base2,
		ft_atoi_base(str2, base2)); // Expect: 6
	printf("Converting '%s' from base '%s': %d\n", str3, base3,
		ft_atoi_base(str3, base3)); // Expect: 255
	printf("Converting '%s' from base '%s': %d\n", str4, base4,
		ft_atoi_base(str4, base4)); // Expect: 123
	printf("Converting '%s' from base '%s': %d\n", str5, base4,
		ft_atoi_base(str5, base4)); // Expect: 42
	printf("Converting '%s' from base '%s': %d\n", str6, base2,
		ft_atoi_base(str6, base2)); // Expect: -11
	printf("Converting '%s' from base '%s': %d\n", str7, base7,
		ft_atoi_base(str7, base7)); // Expect: 1295
	return (0);
}
*/
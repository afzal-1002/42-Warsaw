/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:59:08 by mafzal            #+#    #+#             */
/*   Updated: 2024/09/03 22:23:37 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_character(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] >= 127)
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

int	is_valid_base(char *base)
{
	int	length;

	if (!base || !*base || !check_character(base))
		return (0);
	length = 0;
	while (base[length] != '\0')
		length++;
	if (length < 2)
		return (0);
	return (1);
}

void	display_number_in_base(unsigned int nbr, unsigned int length,
		char *base)
{
	char	digit;

	if (nbr >= length)
		display_number_in_base(nbr / length, length, base);
	digit = base[nbr % length];
	ft_putchar(digit);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	length;
	unsigned int	n;

	n = 0;
	if (!is_valid_base(base))
		return ;
	length = 0;
	while (base[length] != '\0')
		length++;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = (unsigned int)-nbr;
	}
	else
	{
		n = (unsigned int)nbr;
	}
	display_number_in_base(n, length, base);
}

/*
int	main(void)
{
	int	num;

	num = 255; // Test number
	// Testing with valid base strings
	write(1, "Base 2 (binary): ", 17);
	ft_putnbr_base(num, "01"); // Binary (base 2)
	write(1, "\n", 1);
	write(1, "Base 8 (octal): ", 16);
	ft_putnbr_base(num, "01234567"); // Octal (base 8)
	write(1, "\n", 1);
	write(1, "Base 10 (decimal): ", 20);
	ft_putnbr_base(num, "0123456789"); // Decimal (base 10)
	write(1, "\n", 1);
	write(1, "Base 16 (hexadecimal): ", 24);
	ft_putnbr_base(num, "0123456789abcdef"); // Hexadecimal (base 16)
	write(1, "\n", 1);
	// Testing with invalid bases
	write(1, "Base with invalid characters: ", 31);
	ft_putnbr_base(num, "0123456789ABCDEF+"); // Invalid base
	write(1, "\n", 1);
	write(1, "Base with duplicate characters: ", 33);
	ft_putnbr_base(num, "0123456789AAB"); // Invalid base
	write(1, "\n", 1);
	write(1, "Base with too short length: ", 30);
	ft_putnbr_base(num, "0"); // Invalid base
	write(1, "\n", 1);
	return (0);
}
*/
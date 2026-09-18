#include "../../push_swap.h"

char	**ft_split(char const *s)
{
	char	**result;
	char	*str;
	int		count;
	int		i;
	int		words;
	int		start;
	int		finish;

	str = (char *)s;
	count = 0;
	i = 0;
	words = word_count(str);
	printf("Word count: %d\n", words);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		start = i;
		if (str[i] && is_char(str[i]))
		{
			while (str[i] && is_char(str[i]))
				i++;
			finish = i;
			result[count++] = word_dup(str, start, finish);
		}
	}
	result[count] = NULL;
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
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i] && is_char(str[i]))
			count++;
		if (!str)
			break ;
		while (str[i] && is_char(str[i]))
			i++;
		while (str[i] && is_space(str[i]))
			i++;
	}
	printf("Total words counted: %d\n", count);
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

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	is_char(char c)
{
	if (c != ' ' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * sign > 2147483647)
			return (-1);
		if (result * sign < -2147483648)
			return (0);
		i++;
	}
	return ((int)(result * sign));
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

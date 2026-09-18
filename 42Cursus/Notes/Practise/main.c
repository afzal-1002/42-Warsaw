#include "./test.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	print_word(char *input, int start, int end)
{
	int	i;

	i = 0;
	while (input[start] && start < end)
	{
		write(1, &input[i], 1);
		start++;
	}
}

int	main(void)
{
	char		*input;
	int			i;
	int			start;
	int			end;
	char		*word;
	t_person	*person;

	input = readline("minishell$");
	// printf("%s \n", input);
	i = 0;
	while (is_space(input[i]))
		i++;
	while (input[i])
	{
		start = i;
		printf("start %d => ", start);
		while (input[i] && !is_space(input[i]))
			i++;
		end = i;
		printf("end %d \n", end);
		for (int i = start; i <= end; i++)
		{
			write(1, &input[i], 1);
		}
		write(1, "\n", 1);
		i++;
	}
	person = malloc(sizeof(t_person));
	if (!person)
		return (0);
	person->firstName = "MUhammad";
	person->lastName = "Afzal";
	person->index = 0;
	return (0);
}

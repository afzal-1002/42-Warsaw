#include <ctype.h>
#include <stdio.h>

static const char	*input;

int					expr(void);
int					term(void);
int					factor(void);

void	error_token(char c)
{
	printf("Unexpected token '%c'\n", c);
}
void	error_end(void)
{
	printf("Unexpected end\n");
}

char	peek(void)
{
	return (*input);
}
char	get(void)
{
	return (*input++);
}

int	expr(void)
{
	int	res;

	res = term();
	while (peek() == '+')
	{
		get();
		if (!peek())
			return (error_end(), -1);
		res += term();
	}
	return (res);
}

int	term(void)
{
	int	res;

	res = factor();
	while (peek() == '*')
	{
		get();
		if (!peek())
			return (error_end(), -1);
		res *= factor();
	}
	return (res);
}

int	factor(void)
{
	int	res;

	if (isdigit(peek()))
		return (get() - '0');
	if (peek() == '(')
	{
		get();
		res = expr();
		if (!peek())
			return (error_token('('), -1);
		if (get() != ')')
			return (error_token(input[-1]), -1);
		return (res);
	}
	if (!peek())
		return (error_end(), -1);
	return (error_token(peek()), -1);
}

int	main(int ac, char **av)
{
	int	res;

	if (ac != 2)
		return (0);
	input = av[1];
	res = expr();
	if (res == -1)
		return (1);
	if (peek())
		return (error_token(peek()), 1);
	printf("%d\n", res);
}

// 1000    '4'
// 1001    '+'
// 1002    '5'
// 1003    '*'
// 1004    '2'
// 1005    '+'
// 1006    '1'
// 1007    '\0'
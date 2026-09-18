#ifndef TEST_H
# define TEST_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 1024
# endif

typedef struct s_person
{
	char			*firstName;
	char			*lastName;
	int				index;
	struct s_person	*next;
}					t_person;

typedef enum e_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC
}					t_type;

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}					t_token;

// Parse
typedef struct s_redir
{
	t_type			type;
	char			*file;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}					t_cmd;

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#endif
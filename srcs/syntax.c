
#include <sh42.h>

int		syntax_pipe(t_tok *token)
{
	if (token->prev == NULL 
			|| token->prev->type != STRING 
			|| token->next == NULL 
			|| token->next->type != STRING)
	{
		error_exit("syntax error near '|'");
		return (0);
	}
	return (1);
}

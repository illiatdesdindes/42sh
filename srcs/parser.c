
#include <sh42.h>

void	insert(t_tok *token, t_ast *ast)
{
	t_ast	*newast;

	newast = ast_new(token);
	newast->left = ast;
	newast->up = ast->up;
	ast->up = newast;
	if (newast->up != NULL)
		newast->up->right = newast;
}

void	insert_right(t_tok *token, t_ast *ast)
{
	t_ast	*newast;

	newast = ast_new(token);
	ast->right = newast;
	newast->up = ast;
}

int		type_rank(enum e_toktype type)
{
	if (type == STRING)
		return (1);
	if (type == PIPE)
		return (2);
	if (type == AND || type == OR)
		return (3);
	return (4);
}

t_ast	*descend(t_tok *token, t_ast *ast)
{
	if (ast == NULL)
		return (ast_new(token));
	if (type_rank(token->type) < type_rank(ast->type) && ast->right != NULL)
		descend(token, ast->right);
	else if (type_rank(token->type) < type_rank(ast->type)
			&& ast->right == NULL)
		insert_right(token, ast);
	else
		insert(token, ast);
	return (ast);
}

t_ast	*parser(t_tok *token, t_ast *ast)
{
	while (token)
	{
		ast = descend(token, ast);
		ast = ast_root(ast);
		token = token->next;
	}
	return (ast);
}

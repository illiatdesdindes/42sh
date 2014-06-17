
 #include <sh42.h>

t_ast	*ast_new(t_tok *token)
{
	t_ast	*ast;

	ast = (t_ast*)malloc(sizeof(t_ast));
	error_if(ast == NULL, "NULL malloc");
	ast->type = token->type;
	ast->up = NULL;
	ast->left = NULL;
	ast->right = NULL;
	if (token->type == STRING)
		ast->str = token->str;
	return (ast);
}

t_ast	*ast_root(t_ast *ast)
{
	while (ast->up)
		ast = ast->up;
	return (ast);
}

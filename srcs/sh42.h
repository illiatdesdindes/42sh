/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:48:04 by svachere          #+#    #+#             */
/*   Updated: 2014/05/29 17:13:24 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH42_H
# define SH42_H
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

# define GETCWD_SIZE	512

typedef enum	e_toktype
{
	STRING,
	PIPE,
	SEMIC
}				t_toktype;

typedef struct	s_tok
{
	t_toktype		type;
	char			*str;
	struct s_tok	*next;
	struct s_tok	*prev;
}				t_tok;

typedef struct	s_ast
{
	t_toktype		type;
	char			*str;
	struct s_ast	*up;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

int		contentpath(char *file);
void	freestrv(char **strv);
void	strvtrim(char **strv);
int		isbuiltin(char **av);
char	*joinwith(char *path, char *file, char *join);
void	freefindcmd(char **path, char *file);
char	**get_path();
void	putstrv(char **strv);
char	*ft_getenv(char *name);
int		ft_setenv(char *name, char *value, int overwrite);
int		strvput(char **strv, char *s);
int		strvadd(char ***strv, char *s);
void	ft_unsetenv(char *name);
int		copyenv(char **env);
void	bi_setenv(char **av);
void	bi_unsetenv(char **av);
void	bi_printenv(char **av);
void	bi_cd(char **av);
void	bi_exit(char **av);
void	bi_test(char **av);
t_tok	*lexer(char *line);
int		isopsymb(char c);
t_tok	*token_add(t_tok **tokens, t_toktype toktype, char *str);
t_tok	*token_add_string(t_tok **tokens, char *str, int *ilexer);
void	print_tokens(t_tok *tokens);
void	print_ast(t_ast *ast);
int		returncmd(int n, int set);
t_ast	*parser(t_tok *token, t_ast *ast);
t_ast	*syntax(t_tok *token, t_ast *ast);
t_ast	*ast_new(t_tok *token);
t_ast	*ast_root(t_ast *ast);

char	**g_environ;

#endif

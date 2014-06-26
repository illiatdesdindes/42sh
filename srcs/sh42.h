/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh42.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 14:48:04 by svachere          #+#    #+#             */
/*   Updated: 2014/06/26 15:38:20 by apergens         ###   ########.fr       */
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
# define DEBUG			1
# define MULTI_LINE		0
# define SINGLE_LINE	0
# define SET			0
# define GET			1

typedef enum		e_toktype
{
	STRING,
	REDIN,
	REDOUT,
	REDAPP,
	PIPE,
	AND,
	OR,
	SEMIC
}					t_toktype;

typedef struct		s_tok
{
	t_toktype		type;
	char			*str;
	struct s_tok	*next;
	struct s_tok	*prev;
}					t_tok;

typedef struct		s_ast
{
	t_toktype		type;
	char			*str;
	struct s_ast	*up;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct		s_pipe
{
	int				in[2];
	int				out[2];
}					t_pipe;

int					isspce(char c);
char				**ft_strsplitquote(char const *s, char *splitchars);
int					contentpath(char *file);
int					findcmd(char **av, t_pipe pipes);
void				freestrv(char **strv);
void				free_token_ast(t_tok **tok, t_ast **ast);
void				strvtrim(char **strv);
int					isbuiltin(char **av);
char				*joinlines(char **s1, char **s2, int pfree);
char				*joinwith(char *path, char *file, char *join);
void				freefindcmd(char **path, char *file);
char				**get_path();
void				putstrv(char **strv);
char				*ft_getenv(char *name);
int					ft_setenv(char *name, char *value, int overwrite);
int					strvput(char **strv, char *s);
int					strvadd(char ***strv, char *s);
int					ft_unsetenv(char *name, int i, int find);
int					copyenv(char **env);
void				bi_setenv(char **av);
void				bi_unsetenv(char **av);
void				bi_printenv(char **av);
void				bi_cd(char **av);
void				bi_exit(char **av);
void				bi_echo(char **av);
t_tok				*lexer(char *line);
int					isopsymb(char c);
t_tok				*token_add(t_tok **tokens, t_toktype toktype, char *str);
t_tok				*token_add_string(t_tok **tokens, char **str, int *ilexer);
int					token_add_red(t_tok **tokens, char *str, int *i);
void				print_tokens(t_tok *tokens);
void				print_ast(t_ast *ast);
int					returncmd(int n, int set);
t_ast				*parser(t_tok *token, t_ast *ast);
int					syntax(t_tok *token);
t_ast				*ast_new(t_tok *token);
t_ast				*ast_root(t_ast *ast);
int					exec_node(t_ast *ast, t_pipe pipes);
void				stdio_init_dup();
int					stdin_get();
int					stdout_get();
char				**g_environ;
void				sig_handler(int sig);
void				putprompt(void);
void				bi_cd_deleg3(char *get);
int					returnrun(int n, int set);

#endif

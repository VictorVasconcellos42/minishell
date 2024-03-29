/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:14:17 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 13:14:04 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define END "\033[0m"
# define READ_END	0
# define WRITE_END	1

extern int					g_code;

typedef struct s_token		t_token;
typedef struct s_sentence	t_sentence;

typedef struct s_cmd
{
	char		*input;
	char		**env;
	char		**path;
	char		*oldpwd;
	int			env_size;
	int			size_cmd;
	int			backup;
	t_token		*token;
	t_sentence	*sentence;
}	t_cmd;

typedef struct s_sentence
{
	char	**args;
	short	input;
	short	output;
}	t_sentence;

typedef struct s_token
{
	char	*value;
	int		type;
	int		count;
}	t_token;

// BUILTINS ENUM //

typedef enum e_builtin
{
	ENV = 1,
	ECHO,
	EXIT,
	PWD,
	UNSET,
	EXPORT,
	CD
}	t_builtin;

// TOKENS ENUM //

typedef enum e_tokens
{
	WORD = 100,
	PIPE,
	R_INPUT,
	APP_INPUT,
	HERE_DOC,
	R_OUTPUT,
	Q_SIMPLE,
	Q_DOUBLE
}	t_tokens;

// ENV //

void		create_env(t_cmd *cmd, char **envp);
char		**get_path(t_cmd *cmd);

// BUILTIN //

void		child_exec(t_sentence sentence, t_cmd *cmd, int backup);
int			is_builtin(char *input);
int			builtin_env(t_cmd *cmd);
void		builtin_exit(t_sentence sentence, t_cmd *cmd);
int			who_builtin(t_cmd *cmd, int builtin, t_sentence sentence);
int			cd(t_sentence sentence, t_cmd *cmd);
void		pwd(void);
void		export(t_cmd *cmd, char *new_var);
void		unset(t_cmd *cmd, char *str);
int			my_echo(t_sentence sentence, int flag, int i, int j);
int			builtin_export(t_sentence table, t_cmd *cmd, int j);
int			builtin_unset(t_sentence sentence, t_cmd *cmd);

// EXEC //

int			check_command(t_cmd *cmd);
void		execution(t_cmd *exec);
int			check_case(char *str);
void		executor(t_cmd *cmd);
void		execute_sentence(t_sentence sentence, t_cmd *cmd, int backup);
void		the_executor(t_sentence sentence, t_cmd *cmd, int i);
void		the_builtin_executor(t_sentence sentence, t_cmd *cmd);
void		search_parth(t_sentence sentence, t_cmd *cmd);

// SIGNAL //

void		handle_signal(void);
void		handle_ctrl_c(int sig);
void		handle_ctrl_d(void);

// LEAK //

void		control_free(t_cmd *cmd);
void		free_fd(int **input, int size);
void		free_sentence(t_sentence *sentence);
void		free_token(t_token *token);
void		clear_child(t_cmd *cmd);
void		free_code(char **aux);

// PIPEX //

int			has_pipe(char *string, t_cmd *cmd);
void		free_matriz(char **input);
void		pipex(t_sentence *sentence, int i, t_cmd *cmd);

// UTILS //

void		error_command(char *command);
int			matriz_size(char **str);
void		check_input(t_cmd *cmd);
void		error_var(char *var);
int			is_valid_var(char *var);
void		status_check(int *pid);
int			only_space(char *input);
void		restart_shell(t_cmd *cmd);
void		clear_leak(t_cmd *cmd);

//	START	//

void		start_shell(t_cmd *cmd, char **envp);
void		init_minishell(t_cmd *cmd);
int			**init_fd(t_sentence *sentence);
int			step_shell(t_cmd *cmd);

//	EXPANDER	//

char		*search_var(char *id, char **envp);

//	TOKEN	//

char		**tokenize(char const *string);
t_token		*lexer(t_cmd *cmd);
char		**create_sentence(t_cmd *cmd);
t_sentence	*sentence_generator(t_token *token, int i, int count);

//	PARSER	//

int			parser(t_token *token);
int			check(t_token *token);
void		pipeline(t_token *token);
int			redirects(t_token *token);
int			parser_error(char *text);
int			word(t_token *token);
int			file(t_token *token);
int			is_pipes(int type);
int			is_redirect(int type);

// SENTENCE	//

int			how_many_sentences(t_sentence *sentence);
void		child_signal(void);
void		sig_heredoc(int sig);
void		heredoc_signal(void);
void		fork_doc(t_sentence *table, int command, int i);

//	EXPANDER	//

char		*remove_quotes_pair(char *token);

//	REDIRECT	//

int			control_redirect(t_sentence *table, int command, int i);
int			create_file(char *name, int type);
void		remove_redirect(t_sentence sentence);
void		heredoc_action(t_sentence *table, int pos, int i);

//	BOOLEAN	//

int			is_output(char *type);
int			is_input(char *type);
int			is_append(char *type);
int			is_heredoc(char *type);
int			is_str_redirect(char *type);
int			ft_str_isdigit(char *str);
t_token		handling(t_token token, char **envp);

//	QUOTE	//	

int			quote_handling(t_token *tokens, t_cmd *cmd);
#endif

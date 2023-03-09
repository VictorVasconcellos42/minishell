/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:14:17 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/09 04:36:07 by vde-vasc         ###   ########.fr       */
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
# define END_R	0
# define END_W	1

typedef struct s_token t_token;

typedef struct s_cmd
{
	char	*input;

	char	**env;
	int		env_size;

	char	**exec;
	char	**pipex;

	char	**path;

	int		status;
	t_token	*token;
}	t_cmd;

typedef struct s_token
{
	char	*token_value;
	int		type;
} t_token;

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

typedef enum e_tokens
{
	WORD = 100,
	PIPE,
	R_INPUT,
	APP_INPUT,
	HERE_DOC,
	R_OUTPUT
}	t_tokens;

// ENV //

void	create_env(t_cmd *cmd, char **envp);
void	env_path(t_cmd *cmd);

// BUILTIN //

int		is_builtin(char *input);
void	builtin_env(t_cmd *cmd);
void	builtin_exit(t_cmd *cmd);
int		who_builtin(t_cmd *cmd, int builtin);

// EXEC //

void	execution(t_cmd *exec);
int	check_command(t_cmd *cmd);

// SIGNAL //

void	handle_signal(void);
void	handle_ctrl_c(int sig);
void	handle_ctrl_d(void);

// LEAK //

void    control_free(t_cmd *cmd);

// PIPEX //

int		has_pipe(char *string);
int		pipes(t_cmd *cmd);
void    free_matriz(char **input);
#endif

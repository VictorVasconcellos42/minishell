/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:14:17 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/01 20:12:25 by vde-vasc         ###   ########.fr       */
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
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_cmd
{
	char	*input;

	char	**env;
	int		env_size;

	char	**exec;

	char	**path;

	int		status;
}	t_cmd;

void	create_env(t_cmd *cmd, char **envp);
void	builtin_env(t_cmd *cmd);
void	builtin_exit(t_cmd *cmd);
void	env_path(t_cmd *cmd);
void	execution(t_cmd *exec);

#endif

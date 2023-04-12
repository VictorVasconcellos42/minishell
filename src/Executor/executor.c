/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:42:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/11 23:04:41 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*relative_or_absolute(char *command)

{
	if (command[0] == '/' || command[0] == '.')
		return (ft_strdup(command));
	return (ft_strdup(" "));
}

void	the_executor(t_sentence sentence, t_cmd *cmd)

{
	char	**table_path;
	char	*full_path;
	int		i;

	table_path = get_path(cmd);
	i = -1;
	full_path = relative_or_absolute(sentence.args[0]);
	while (table_path[++i])
	{
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(sentence.args[0]);
			sentence.args[0] = full_path;
			remove_redirect(sentence);
			execve(sentence.args[0], sentence.args, cmd->env);
		}
		free(full_path);
		full_path = ft_strjoin(table_path[i], "/");
		full_path = ft_strjoin_gnl(full_path, sentence.args[0]);
	}
	printf("bash: %s: command not found\n", sentence.args[0]);
	clear_child(cmd, full_path);
	exit(127);
}

void	the_builtin_executor(t_sentence sentence, t_cmd *cmd)

{
	int	build;

	build = is_builtin(sentence.args[0]);
	remove_redirect(sentence);
	if (build == ENV)
		g_code = builtin_env(cmd);
	else if (build == EXPORT)
		g_code = builtin_export(sentence, cmd, 0);
	else if (build == EXIT)
		builtin_exit(sentence);
	exit(g_code);
}

static void	status_check(int *status)

{
	if (WIFEXITED(status) == 0)
		g_code = 127;
	else if (WIFEXITED(status))
		g_code = WEXITSTATUS(status);
}

void	execute_sentence(t_sentence sentence, t_cmd *cmd, int pid)

{
	int	backup;
	int	status[1];

	backup = dup(STDOUT_FILENO);
	pid = fork();
	status[0] = 0;
	if (pid == 0)
	{
		if (sentence.input != STDIN_FILENO)
		{
			dup2(sentence.input, STDIN_FILENO);
			close(sentence.input);
		}
		if (sentence.output != STDOUT_FILENO)
		{
			dup2(sentence.output, STDOUT_FILENO);
			close(sentence.output);
		}
		remove_redirect(sentence);
		the_executor(sentence, cmd);
	}
	dup2(backup, STDOUT_FILENO);
	waitpid(pid, status, 0);
	status_check(status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:42:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 09:38:44 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	relative_executor(t_sentence table, t_cmd *cmd)

{
	char	*temp;

	temp = getcwd(NULL, 0);
	if (access(table.args[0], F_OK | X_OK) == 0)
	{
		remove_redirect(table);
		execve(table.args[0], table.args, cmd->env);
	}
	perror(table.args[0] + ft_strlen(temp) + 1);
	clear_child(cmd);
	free(temp);
	free(cmd->oldpwd);
	if (errno == 13)
		exit(126);
	exit(127);
}

static char	*check_path(char *command, t_sentence sentence, t_cmd *cmd)

{
	char	*relative;

	if (command[0] == '/')
		return (ft_strdup(command));
	else if (command[0] == '.')
	{
		search_parth(sentence, cmd);
		relative = ft_strjoin_gnl(getcwd(NULL, 0), command + cmd->size_cmd);
		cmd->oldpwd = search_var("PWD", cmd->env);
		free(sentence.args[0]);
		chdir(cmd->oldpwd);
		sentence.args[0] = relative;
		relative_executor(sentence, cmd);
		return (NULL);
	}
	return (ft_strdup(" "));
}

void	the_executor(t_sentence sentence, t_cmd *cmd)

{
	char	**table_path;
	char	*full_path;
	int		i;

	i = -1;
	full_path = check_path(sentence.args[0], sentence, cmd);
	table_path = get_path(cmd);
	while (table_path[++i])
	{
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(sentence.args[0]);
			sentence.args[0] = full_path;
			remove_redirect(sentence);
			execve(sentence.args[0], sentence.args, cmd->env);
			break ;
		}
		free(full_path);
		full_path = ft_strjoin(table_path[i], "/");
		full_path = ft_strjoin_gnl(full_path, sentence.args[0]);
	}
	printf("bash: %s: command not found\n", sentence.args[0]);
	clear_child(cmd);
	free_code(full_path, table_path);
	exit(127);
}

void	the_builtin_executor(t_sentence sentence, t_cmd *cmd)

{
	int	build;

	build = is_builtin(sentence.args[0]);
	remove_redirect(sentence);
	g_code = 0;
	if (build == ENV)
		g_code = builtin_env(cmd);
	else if (build == EXPORT)
		g_code = builtin_export(sentence, cmd, 0);
	else if (build == EXIT)
		builtin_exit(sentence, cmd);
	else if (build == ECHO)
		g_code = my_echo(sentence, 1, 0, 0);
	else if (build == PWD)
		pwd();
	else if (build == EXPORT)
		g_code = builtin_export(sentence, cmd, 0);
	else if (build == UNSET)
		g_code = builtin_unset(sentence, cmd);
	exit(g_code);
}

void	execute_sentence(t_sentence sentence, t_cmd *cmd, int backup)

{
	int	pid;

	backup = dup(STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		child_signal();
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
		if (is_builtin(sentence.args[0]) != 0)
			the_builtin_executor(sentence, cmd);
		close(backup);
		the_executor(sentence, cmd);
	}
	dup2(backup, STDOUT_FILENO);
	close(backup);
	status_check(&pid);
}

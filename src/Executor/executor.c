/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:42:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 22:31:17 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	the_executor(t_sentence sentence, t_cmd *cmd)

{
	char	**table_path;
	char	*full_path;
	int		i;

	table_path = get_path(cmd);
	full_path = NULL;
	i = -1;
	if (sentence.args[0][0] == '/' || sentence.args[0][0] == '.')
		full_path = ft_strdup(sentence.args[0]);
	while (table_path[++i])
	{
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(sentence.args[0]);
			sentence.args[0] = ft_strdup(full_path);
			execve(sentence.args[0], sentence.args, cmd->env);
		}
		free(full_path);
		full_path = ft_strjoin(table_path[i], "/");
		full_path = ft_strjoin_gnl(full_path, sentence.args[0]);
	}
	printf("bash: %s: command not found\n", sentence.args[0]);
	exit(127);
}

void	remove_redirect(t_sentence sentence)

{
	int		i;
	int		origin;
	char	*temp;

	origin = 0;
	i = 0;
	while (sentence.args[i])
	{
		while (sentence.args[i] && is_str_redirect(sentence.args[i]))
		{
			if (is_heredoc(sentence.args[i]))
				unlink(sentence.args[i + 1]);
			i += 2;
		}
		if (sentence.args[i] == NULL)
			break ;
		temp = ft_strdup(sentence.args[i]);
		free(sentence.args[i]);
		sentence.args[origin++] = ft_strdup(temp);
		free(temp);
		i++;
	}
	sentence.args[origin] = NULL;
}

void	execute_sentence(t_sentence sentence, t_cmd *cmd)

{
	int	pid;
	int	backup;

	backup = dup(STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		if (sentence.input != STDIN_FILENO)
			dup2(sentence.input, STDIN_FILENO);
		if (sentence.output != STDOUT_FILENO)
			dup2(sentence.output, STDOUT_FILENO);
		remove_redirect(sentence);
		the_executor(sentence, cmd);
	}
	dup2(backup, STDOUT_FILENO);
	waitpid(pid, NULL, 0);
}

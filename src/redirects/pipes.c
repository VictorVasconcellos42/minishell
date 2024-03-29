/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:26:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 13:10:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	first_pipe(t_sentence *table, int *fd, t_cmd *cmd)

{
	close(fd[READ_END]);
	child_signal();
	if (table[0].output == STDOUT_FILENO)
		dup2(fd[WRITE_END], STDOUT_FILENO);
	if (table[0].output != STDOUT_FILENO)
		dup2(table[0].output, STDOUT_FILENO);
	if (table[0].input != STDIN_FILENO)
		dup2(table[0].input, STDIN_FILENO);
	close(fd[WRITE_END]);
	if (is_builtin(table[0].args[0]) != 0)
		the_builtin_executor(table[0], cmd);
	else
		the_executor(table[0], cmd, -1);
}

static void	middle_pipe(t_cmd *cmd, int i, int **fd, t_sentence *table)

{
	close(fd[i][READ_END]);
	if (table[i].input == STDIN_FILENO)
		dup2(fd[i - 1][READ_END], STDIN_FILENO);
	else
		dup2(table[i].input, STDIN_FILENO);
	close(fd[i - 1][READ_END]);
	if (table[i].output == STDOUT_FILENO)
		dup2(fd[i][WRITE_END], STDOUT_FILENO);
	else
		dup2(table[i].output, STDOUT_FILENO);
	close(fd[i][WRITE_END]);
	if (is_builtin(table[i].args[0]) != 0)
		the_builtin_executor(table[i], cmd);
	else
		the_executor(table[i], cmd, -1);
}

static void	last_pipe(t_cmd *cmd, int i, int *fd, t_sentence *table)

{
	if (table[i].input == STDIN_FILENO)
		dup2(fd[READ_END], STDIN_FILENO);
	if (table[i].output != STDOUT_FILENO)
		dup2(table[i].output, STDOUT_FILENO);
	if (table[i].input != STDIN_FILENO)
		dup2(table[i].input, STDIN_FILENO);
	close(fd[READ_END]);
	if (is_builtin(table[i].args[0]) != 0)
		the_builtin_executor(table[i], cmd);
	else
		the_executor(table[i], cmd, -1);
}

static int	multiple_pipes(t_cmd *cmd, int i, int *pid, int **fd)

{
	int	count;

	count = how_many_sentences(cmd->sentence);
	while (i < count - 2)
	{
		pipe(fd[++i]);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			child_signal();
			middle_pipe(cmd, i, fd, cmd->sentence);
		}
		close(fd[i - 1][0]);
		close(fd[i][1]);
	}
	return (i);
}

void	pipex(t_sentence *sentence, int i, t_cmd *cmd)

{
	int	**fd;
	int	*pid;

	fd = init_fd(sentence);
	pid = ft_calloc(sizeof(int), how_many_sentences(sentence) + 1);
	pipe(fd[i]);
	pid[i] = fork();
	if (pid[i] == 0)
		first_pipe(sentence, fd[i], cmd);
	close(fd[i][WRITE_END]);
	i = multiple_pipes(cmd, i, pid, fd);
	pid[i + 1] = fork();
	if (pid[i + 1] == 0)
		last_pipe(cmd, i + 1, fd[i], sentence);
	close(fd[i][READ_END]);
	status_check(pid);
	free(pid);
	free_fd(fd, how_many_sentences(sentence) - 1);
}

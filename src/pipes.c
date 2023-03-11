/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:26:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/11 11:27:01 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	has_pipe(char *string, t_cmd *cmd)

{
	int i;

    i = 0;
	cmd->c_pipes = 0;
	while (string[i])
	{
		if (ft_strchr("|", string[i++]))
			cmd->c_pipes++;
	}
	if (cmd->c_pipes != 0)
	    return (TRUE);
	return (FALSE);
}

int    **init_fd(t_cmd *cmd)

{
	int i;
	int **fd;

	i = 0;
	cmd->pipex = ft_split(cmd->input, '|');
    fd = malloc(sizeof(int *) * cmd->c_pipes);
	while (i < cmd->c_pipes)
		fd[i++] = malloc(sizeof(int) * 2);
	return (fd);
}

void	pipes(t_cmd *cmd, int i, int j)

{
	int	**fd;
	int	*pid;

	fd = init_fd(cmd);
	pid = (int *)malloc(sizeof(int) * cmd->c_pipes + 1);
	pipe(fd[i]);
	pid[i] = fork();
	if (pid[i] == 0)
		first_pipe(cmd, fd[i]);
	close(fd[i][WRITE_END]);
	while (i < cmd->c_pipes - 1)
	{
		pipe(fd[++i]);
		pid[i] = fork();
		if (pid[i] == 0)
		    middle_pipe(cmd, i, fd);
		close(fd[i - 1][0]);
		close(fd[i][1]);
	}
	pid[i + 1] = fork();
	if (pid[i + 1] == 0)
		last_pipe(cmd, i + 1, fd[i]);
	close(fd[i][READ_END]);
	while (pid[j])
		waitpid(pid[j++], NULL, 0);
}

void first_pipe(t_cmd *cmd, int *fd)

{
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT_FILENO);
	close(fd[WRITE_END]);
	cmd->exec = ft_split(cmd->pipex[0], ' ');
	if (check_command(cmd) == FALSE)
		error_command(cmd->exec[0]);
	exit(127);
}

void middle_pipe(t_cmd *cmd, int i, int **fd)

{
	close(fd[i][READ_END]);
	dup2(fd[i - 1][READ_END], STDIN_FILENO);
	close(fd[i - 1][READ_END]);
	dup2(fd[i][WRITE_END], STDOUT_FILENO);
	close(fd[i][WRITE_END]);
	cmd->exec = ft_split(cmd->pipex[i], ' ');
	if (check_command(cmd) == FALSE)
		error_command(cmd->exec[0]);
	exit(127);
}

void last_pipe(t_cmd *cmd, int i, int *fd)

{
	dup2(fd[READ_END], STDIN_FILENO);
	close(fd[READ_END]);
	cmd->exec = ft_split(cmd->pipex[i], ' ');
	if (check_command(cmd) == FALSE)
		error_command(cmd->exec[0]);
	exit(127);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:26:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/10 07:01:40 by vde-vasc         ###   ########.fr       */
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

/* int    **init_fd(int **fd, t_cmd *cmd)

{
	int i;

	i = 0;
    fd = malloc(sizeof(int *) * cmd->c_pipes);
	while (i < cmd->c_pipes)
		fd[i++] = malloc(sizeof(int) * 2);
	return (fd);
} */

void	pipes(t_cmd *cmd)

{
	int i;
	int	**fd;
	int	*pid;

    i = 0;
	fd = malloc(sizeof(int *) * cmd->c_pipes);
	while (i < cmd->c_pipes)
		fd[i++] = malloc(sizeof(int) * 2);
	pid = (int *)malloc(sizeof(int) * cmd->c_pipes + 1);
	i = 0;
	cmd->pipex = ft_split(cmd->input, '|');
	pipe(fd[i]);
	pid[i] = fork();
	if (pid[i] == 0)
		first_pipe(cmd, fd[i]);
	close(fd[i][1]);
	while (i < cmd->c_pipes - 1)
	{
		i++;
		pipe(fd[i]);
		pid[i] = fork();
		if (pid[i] == 0)
		    middle_pipe(cmd, i, fd);
		close(fd[i - 1][0]);
		close(fd[i][1]);
	}
	pid[i + 1] = fork();
	if (pid[i + 1] == 0)
		last_pipe(cmd, i + 1, fd[i]);
	close(fd[i][0]);
	i = 0;
	while (pid[i])
		waitpid(pid[i++], NULL, 0);
}

void first_pipe(t_cmd *cmd, int *fd)

{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	cmd->exec = ft_split(cmd->pipex[0], ' ');
	check_command(cmd);
}

void middle_pipe(t_cmd *cmd, int i, int **fd)

{
	close(fd[i][0]);
	dup2(fd[i - 1][0], STDIN_FILENO);
	close(fd[i - 1][0]);
	dup2(fd[i][1], STDOUT_FILENO);
	close(fd[i][1]);
	cmd->exec = ft_split(cmd->pipex[i], ' ');
	check_command(cmd);
}

void last_pipe(t_cmd *cmd, int i, int *fd)

{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	cmd->exec = ft_split(cmd->pipex[i], ' ');
	check_command(cmd);
}
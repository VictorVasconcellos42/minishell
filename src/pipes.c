/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:26:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/09 00:31:33 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	has_pipe(char *string)

{
	int i = 0;

	while (string[i])
	{
		if (ft_strchr("|", string[i++]))
			return (TRUE);
	}
	return (FALSE);
}

int	pipes(t_cmd *cmd)

{
    int	fd1[2];
	//int	fd2[2];
	int	pid;
	int	status;

	status = 0;
	cmd->pipex = ft_split(cmd->input, '|');
	pipe(fd1);
	pid = fork();
	if (pid == 0)
	{
		close(fd1[END_R]);
		dup2(fd1[END_W], STDOUT_FILENO);
		close(fd1[END_W]);
		cmd->exec = ft_split(cmd->pipex[0], ' ');
		if (check_command(cmd) == FALSE)
			printf("bash: %s: command not found\n", cmd->exec[0]);
		exit(127);
	}
	else
	{
		close(fd1[END_W]);
		pid = fork();
		if (pid == 0)
		{
            dup2(fd1[END_R], STDIN_FILENO);
            close(fd1[END_R]);
			cmd->exec = ft_split(cmd->pipex[1], ' ');
		if (check_command(cmd) == FALSE)
			printf("bash: %s: command not found\n", cmd->exec[0]);
		}
		else
			close(fd1[END_R]);
	}
	wait(&status);
	wait(&status);
	return (0);
}
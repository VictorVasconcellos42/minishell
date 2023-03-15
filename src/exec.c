/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:43:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/15 09:51:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_command(t_cmd *cmd)

{
	int		i;
	char	*full_path;

	if (cmd->exec[0][0] == '/' || cmd->exec[0][0] == '.')
		full_path = ft_strdup(cmd->exec[0]);
	i = 0;
	while (cmd->path[i])
	{
		if (access(full_path, F_OK | X_OK) == 0)
		{
			cmd->exec[0] = ft_strdup(full_path);
			free(full_path);
			execve(cmd->exec[0], cmd->exec, cmd->env);
			return (TRUE);
		}
		full_path = ft_strjoin(cmd->path[i], "/");
		full_path = ft_strjoin_gnl(full_path, cmd->exec[0]);
		i++;
	}
	free(full_path);
	return (FALSE);
}

void	execution(t_cmd *cmd)

{
	int		pid;

	cmd->exec = ft_split(cmd->input, ' ');
	pid = fork();
	if (pid == 0)
	{
		if (check_command(cmd) == FALSE)
			printf("bash: %s: command not found\n", cmd->exec[0]);
		exit(127);
	}
	else
		wait(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:43:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/01 19:52:03 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_command(t_cmd *cmd)

{
	int		i;
	char	*full_path;

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
		free(full_path);
		full_path = ft_strjoin(cmd->path[i], "/");
		full_path = ft_strjoin(full_path, cmd->exec[0]);
		i++;
	}
	return (FALSE);
}

void	execution(t_cmd *cmd)

{
	int		pid;

	pid = fork();
	cmd->exec = ft_split(cmd->input, ' ');
	if (pid == 0)
		check_command(cmd);
	else
		wait(0);
}

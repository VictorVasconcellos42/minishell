/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:43:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/17 09:08:28 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//TODO:  Protect malloc

int	check_command(t_cmd *cmd)

{
	int		i;
	char	*full_path;
	char	**path_table;

	i = -1;
	path_table = get_path(cmd);
	full_path = NULL;
	if (cmd->exec[0][0] == '/' || cmd->exec[0][0] == '.')
		full_path = ft_strdup(cmd->exec[0]);
	while (path_table[++i])
	{
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free(cmd->exec[0]);
			cmd->exec[0] = ft_strdup(full_path);
			free(full_path);
			free_matriz(path_table);
			execve(cmd->exec[0], cmd->exec, cmd->env);
			return (TRUE);
		}
		free(full_path);
		full_path = ft_strjoin(path_table[i], "/");
		full_path = ft_strjoin_gnl(full_path, cmd->exec[0]);
	}
	return (free(full_path), free_matriz(path_table), FALSE);
}

void	execution(t_cmd *cmd)

{
	int		pid;

	cmd->exec = ft_split(cmd->input, ' ');
	pid = fork();
	if (pid == 0)
	{
		if (check_command(cmd) == FALSE)
		{
			printf("bash: %s: command not found\n", cmd->exec[0]);
			free_matriz(cmd->exec);
			exit(127);
		}
		free_matriz(cmd->exec);
		exit(EXIT_SUCCESS);
	}
	else
		wait(0);
}

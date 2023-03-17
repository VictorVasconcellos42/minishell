/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:47:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/17 16:02:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	start_shell(t_cmd *cmd, char **envp)

{
	init_minishell(cmd);
	create_env(cmd, envp);
}

void	init_minishell(t_cmd *cmd)

{
	cmd->exec = NULL;
	cmd->env = NULL;
	cmd->path = NULL;
	cmd->pipex = NULL;
	cmd->token = NULL;
	cmd->c_pipes = 0;
	cmd->sys_env = 0;
}

int	**init_fd(t_cmd *cmd)

{
	int	i;
	int	**fd;

	i = 0;
	cmd->pipex = ft_split(cmd->input, '|');
	fd = malloc(sizeof(int *) * cmd->c_pipes);
	while (i < cmd->c_pipes)
		fd[i++] = malloc(sizeof(int) * 2);
	return (fd);
}

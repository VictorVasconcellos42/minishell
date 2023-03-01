/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:08 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/01 18:40:20 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	env_path(t_cmd *cmd)

{
	int		i;
	char	*tmp;

	i = 0;
	while (cmd->env[i])
	{
		if (!ft_strncmp(cmd->env[i], "PATH", 4))
		{
			tmp = ft_strdup(cmd->env[i]);
			cmd->path = ft_split(tmp + 5, ':');
			break ;
		}
		i++;
	}
}

static int	env_size(char **str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	create_env(t_cmd *cmd, char **envp)

{
	int	i;

	i = -1;
	cmd->env_size = env_size(envp);
	cmd->env = malloc(sizeof(char *) * (cmd->env_size + 1));
	if (!cmd->env)
		return ;
	while (++i < cmd->env_size)
		cmd->env[i] = ft_strdup(envp[i]);
	env_path(cmd);
}

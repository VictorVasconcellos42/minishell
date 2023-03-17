/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:08 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/17 05:08:50 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**get_path(t_cmd *cmd)

{
	int		i;
	char	*tmp;
	char	**path;

	i = -1;
	path = NULL;
	while (cmd->env[++i])
	{
		if (!ft_strncmp(cmd->env[i], "PATH=", 5))
		{
			tmp = ft_strdup(cmd->env[i]);
			if (!tmp)
				return (NULL);
			path = ft_split(tmp + 5, ':');
			if (!path)
				return (free(tmp), NULL);
			free(tmp);
			break ;
		}
	}
	return (path);
}

int	matriz_size(char **str)

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
	int	size;

	i = 0;
	size = matriz_size(envp);
	cmd->env = malloc(sizeof(char *) * (size + 1));
	if (!cmd->env)
		return ;
	while (i < size)
	{
		cmd->env[i] = ft_strdup(envp[i]);
		i++;
	}
	cmd->env[i] = NULL;
}

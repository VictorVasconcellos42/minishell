/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:08 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/28 02:40:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
}

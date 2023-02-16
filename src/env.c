/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:30:08 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/16 11:41:17 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	env_size(char **str)

{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void    create_env(t_cmd *cmd, char **envp)

{
    int i;

    i = 0;
    cmd->env_size = env_size(envp);
    cmd->env = malloc(sizeof(char *) * (cmd->env_size + 1));
    while (i < cmd->env_size - 1)
    {
        cmd->env[i] = envp[i];
        printf("%s\n", cmd->env[i++]);
    }
    i = 0;
}
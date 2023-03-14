/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:07:05 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/14 15:51:10 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	export(t_cmd *cmd, char *new_var)

{
	int	i;
	int	j;
	char **export;

    i = 0;
	j = 0;
	export = ft_split(new_var, ' ');
	while (export[1][j] != '=')
		j++;
	while (cmd->env[i])
	{
		if (!ft_strncmp(cmd->env[i], export[1], j))
		{
			free(cmd->env[i]);
			cmd->env[i] = ft_substr(export[1], 0, ft_strlen(export[1]));
			create_env(cmd, cmd->env);
			return ;
		}
		i++;
	}
	cmd->env[i] = ft_substr(export[1], 0, ft_strlen(export[1]));
	create_env(cmd, cmd->env);
}
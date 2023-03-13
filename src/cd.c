/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:18:17 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/12 17:05:25 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	cd(char **cmd_table, t_cmd *cmd)

{
	int	i;

	i = -1;
	if (matriz_size(cmd_table) == 1)
	{
		while (cmd->env[++i])
		{
			if (!ft_strncmp(cmd->env[i], "HOME=", 5))
			{
				chdir(cmd->env[i] + 5);
				return (1);
			}
		}
	}
	chdir(cmd->cd[1]);
	return (0);
}
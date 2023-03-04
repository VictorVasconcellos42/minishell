/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2023/03/04 16:22:55 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(char *input)

{
	if (!ft_strncmp(input, "env", 3))
		return (ENV);
	else if (!ft_strncmp(input, "exit", 4))
			return (EXIT);
	return (FALSE);
}

void	builtin_env(t_cmd *cmd)

{
	int	i;

	i = 0;
	while (cmd->env[i])
		printf("%s\n", cmd->env[i++]);
}

void	builtin_exit(t_cmd *cmd)

{
	cmd->status = 1;
	printf("exit\n");
	if (cmd->status == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int	who_builtin(t_cmd *cmd, int builtin)

{
	if (builtin == 0)
		return (FALSE);
	else if (builtin == ENV)
		builtin_env(cmd);
	else if (builtin == EXIT)
		builtin_exit(cmd);
	return (TRUE);
}

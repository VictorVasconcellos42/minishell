/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2023/03/13 23:53:22 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(char *input)

{
	if (!ft_strncmp(input, "env", 3))
		return (ENV);
	else if (!ft_strncmp(input, "exit", 4))
		return (EXIT);
	else if (!ft_strncmp(input, "cd", 2))
	    return (CD);
	else if(!ft_strncmp(input, "pwd", -1))
		return (PWD);
	else if (!ft_strncmp(input, "export", 6))
	    return (EXPORT);
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
	control_free(cmd);
	printf("exit\n");
	if (!(cmd->status == 0))
		exit(cmd->status);
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
	else if (builtin == CD)
	    cd(cmd->cd, cmd);
	else if (builtin == PWD)
		pwd(cmd);
	else if (builtin == EXPORT)
		export(cmd, cmd->input);
	return (TRUE);
}

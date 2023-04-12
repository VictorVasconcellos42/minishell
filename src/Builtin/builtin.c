/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2023/04/12 07:15:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *input)

{
	if (!ft_strncmp(input, "env", -1))
		return (ENV);
	else if (!ft_strncmp(input, "exit", -1))
		return (EXIT);
	else if (!ft_strncmp(input, "cd", -1))
		return (CD);
	else if (!ft_strncmp(input, "pwd", -1))
		return (PWD);
	else if (!ft_strncmp(input, "echo", -1))
		return (ECHO);
	else if (!ft_strncmp(input, "export", -1))
		return (EXPORT);
	else if (!ft_strncmp(input, "unset", -1))
		return (UNSET);
	return (FALSE);
}

int	who_builtin(t_cmd *cmd, int builtin, t_sentence sentence)
{
	if (builtin == 0)
		return (FALSE);
	else if (builtin == ENV)
		builtin_env(cmd);
	else if (builtin == EXIT)
		builtin_exit(sentence, cmd);
	else if (builtin == CD)
		cd(sentence, cmd);
	else if (builtin == PWD)
		pwd();
	else if (builtin == ECHO)
		my_echo(sentence, 1, 0, 0);
	else if (builtin == EXPORT)
		builtin_export(sentence, cmd, 1);
	else if (builtin == UNSET)
		builtin_unset(sentence, cmd);
	return (TRUE);
}

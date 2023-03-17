/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:14:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/17 16:04:28 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	error_command(char *command)

{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

int	has_pipe(char *string, t_cmd *cmd)

{
	int	i;

	i = 0;
	cmd->c_pipes = 0;
	while (string[i])
	{
		if (ft_strchr("|", string[i++]))
			cmd->c_pipes++;
	}
	if (cmd->c_pipes != 0)
		return (TRUE);
	return (FALSE);
}

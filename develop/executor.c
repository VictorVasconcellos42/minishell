/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:42:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/04 00:31:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	redirect(t_cmd *cmd)

{
	(void)cmd;
	return ;
}

void	pipes_and_red(t_cmd *cmd)

{
	(void)cmd;
	return ;
}

void	executor(t_cmd *cmd)

{
	int	status;

	status = check_case(cmd->input);
	if (!status)
		return ;
	else if (status == 1)
		pipes_and_red(cmd);
	else if (status == 2)
		pipes(cmd, 0, 0);
	else if (status == 3)
		redirect(cmd);
}
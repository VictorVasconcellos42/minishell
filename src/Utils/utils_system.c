/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:20:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2024/04/01 19:00:44 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_input(t_cmd *cmd)

{
	if (!(cmd->input))
	{
		control_free(cmd);
		handle_ctrl_d();
	}
	else if (!cmd->input[0])
	{
		free(cmd->input);
		cmd->input = NULL;
	}
	else if (cmd->input[0] != '\0')
		add_history(cmd->input);
	return ;
}

void	free_token(t_token *token)

{
	int	i;

	i = 0;
	while (token[i].value)
		free(token[i++].value);
	free(token);
}

void	free_sentence(t_sentence *sentence)

{
	int	i;

	i = 0;
	while (sentence[i].args)
		free_matriz(sentence[i++].args);
	free(sentence);
}

void	clear_child(t_cmd *cmd)

{
	free_sentence(cmd->sentence);
	free(cmd->input);
	free_token(cmd->token);
	free_matriz(cmd->env);
}

void	status_check(int *pid)

{
	int	status;

	status = 0;
	while (*pid)
	{
		waitpid(*pid, &status, 0);
		pid++;
	}
	if (WIFEXITED(status))
		g_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_code = 128 + WTERMSIG(status);
}

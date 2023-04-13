/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:15:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/13 13:24:53 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	which_routine(t_cmd *cmd)

{
	int	build;
	int	backup;

	backup = dup(STDOUT_FILENO);
	build = is_builtin(cmd->sentence->args[0]);
	if (how_many_sentences(cmd->sentence) > 1)
		pipex(cmd->sentence, 0, cmd);
	else if (build != 0)
	{
		remove_redirect(cmd->sentence[0]);
		check_fd(cmd->sentence[0]);
		who_builtin(cmd, build, cmd->sentence[0]);
		dup2(backup, STDOUT_FILENO);
	}
	else
		execute_sentence(cmd->sentence[0], cmd, 0);
}

int	step_shell(t_cmd *cmd)

{
	if (parser(cmd->token))
	{
		cmd->sentence = sentence_generator(cmd->token, -1, 0);
		if (!control_redirect(cmd->sentence, -1, -1))
			return (FALSE);
		else
			which_routine(&cmd);
	}
	return (TRUE);
}

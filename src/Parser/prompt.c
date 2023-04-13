/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/12 21:12:53 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_code = 0;

static void	clear_leak(t_cmd *cmd)

{
	free_sentence(cmd->sentence);
	free_token(cmd->token);
	free(cmd->input);
}

static void	check_fd(t_sentence sentence)

{
	if (sentence.output != STDOUT_FILENO)
	{
		dup2(sentence.output, STDOUT_FILENO);
		close(sentence.output);	
	}
	if (sentence.input != STDIN_FILENO)
	{
		dup2(sentence.input, STDIN_FILENO);
		close(sentence.input);	
	}
}

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

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;

	if (argc == 1 && argv[0])
	{
		start_shell(&cmd, envp);
		while (1)
		{
			handle_signal();
			cmd.input = readline("Minishell: ");
			check_input(&cmd);
			if (!cmd.input || !(cmd.input[0]) || only_space(cmd.input))	
				continue ;
			cmd.token = lexer(&cmd);
			quote_handling(cmd.token);
			if (parser(cmd.token))
			{
				cmd.sentence = sentence_generator(cmd.token, -1, 0);
				if (!control_redirect(cmd.sentence, -1, -1))
					continue ;
				else
					which_routine(&cmd);
			}
			clear_leak(&cmd);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/11 17:56:49 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_code = 0;

void	free_token(t_token *token)

{
	int i;

	i = 0;
	while (token[i].value)
		free(token[i++].value);
	free(token);
}

void	free_sentence(t_sentence *sentence)

{
	int i;

	i = 0;
	while (sentence[i].args)
		free_matriz(sentence[i++].args);
	free(sentence);
}

void	check_input(t_cmd *cmd)

{
	if (!(cmd->input))
	{
		control_free(cmd);
		handle_ctrl_d();
	}
	else if (!cmd->input[0])
		free(cmd->input);
	else if (cmd->input[0] != '\0')
		add_history(cmd->input);
	return ;
}

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;
	int		build;

	(void)argc;
	(void)argv;
	start_shell(&cmd, envp);
	while (1)
	{
		handle_signal();
		cmd.input = readline("Minishell: ");
		check_input(&cmd);
		if (!cmd.input || !(cmd.input[0]))	
			continue ;
		cmd.token = lexer(&cmd);
		quote_handling(cmd.token);
		if (parser(cmd.token))
		{
			cmd.sentence = sentence_generator(cmd.token, -1, 0);
			build = is_builtin(cmd.sentence->args[0]);
			if (who_builtin(&cmd, build, cmd.sentence[0]) == FALSE)
			{
				if (!control_redirect(cmd.sentence, -1, -1))
					continue ;
				else
				{
					if (how_many_sentences(cmd.sentence) > 1)
						pipex(cmd.sentence, 0, 0, &cmd);
					else
						execute_sentence(cmd.sentence[0], &cmd);
				}
			}
			free_sentence(cmd.sentence);
			free_token(cmd.token);
		}
	}
	return (0);
}

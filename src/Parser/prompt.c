/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 23:05:30 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_code = 0;

void	check_input(char *input, t_cmd *cmd)

{
	if (!(input))
	{
		control_free(cmd);
		handle_ctrl_d();
	}
	else if (input[0] != '\0')
		add_history(input);
	return ;
}

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;
	int		build;

	(void)argc;
	(void)argv;
	start_shell(&cmd, envp);
	handle_signal();
	while (1)
	{
		cmd.input = readline("Minishell: ");
		check_input(cmd.input, &cmd);
		if (!cmd.input[0])
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
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/08 15:08:34 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	check_input(char *input, t_cmd *cmd)

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
	int		test = 0;
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
		if(cmd.token->value[0] == '$')
			dolleta(&cmd);
		/* {
			if(dolleta(&cmd))
				printf("%s\n", dolleta(&cmd));
		} */
		if (parser(cmd.token))
		{
			if (test == 1)
			{
				cmd.sentence = sentence_generator(cmd.token, &cmd);
				control_redirect(cmd.sentence);
				int i = 0;
				while (cmd.sentence[i].args)
				{
					execute_sentence(cmd.sentence[i++], &cmd);
				}
/* 				int j = 0;
				int i = -1;
				while (cmd.sentence[j].args)
				{
					i = -1;
					while (cmd.sentence[j].args[++i])
						printf("SENTENCE [%d] - ARGS [%d]: {%s}\n", j, i, cmd.sentence[j].args[i]);
					if (cmd.sentence[j].args != NULL)
						printf("==================\n");
					j++;
				} */
			}
			else
			{
				cmd.cd = ft_split(cmd.input, ' ');
				cmd.echo = ft_split(cmd.input, ' ');
				build = is_builtin(cmd.input);
				if (who_builtin(&cmd, build) == FALSE)
				{
					if (has_pipe(cmd.input, &cmd) == TRUE)
						pipes(&cmd, 0, 0);
					else
						execution(&cmd);
				}
				free_matriz(cmd.cd);
			}
		}
		free(cmd.input);
	}
	builtin_exit(&cmd);
	return (0);
}

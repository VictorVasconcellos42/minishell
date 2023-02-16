/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/16 13:02:09 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_builtin(char *input)

{
	return (!strncmp(input, "env", -1) || !strncmp(input, "echo", -1));
}

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;

	(void)argc;
	(void)argv;
	while (1)
	{
		cmd.input = readline("$ ");
		add_history(cmd.input);
		if (!strcmp(cmd.input, "exit"))
			break ;
		if (is_builtin(cmd.input))
			create_env(&cmd, envp);
		free(cmd.input);
	}
	free(cmd.input);
	return (0);
}

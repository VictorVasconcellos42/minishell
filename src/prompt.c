/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/16 11:39:53 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_builtin(char *input)

{
	return (!strncmp(input, "env", -1) || !strncmp(input, "echo", -1));
}

int	len(char **str)

{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv, char **envp)

{
	(void)argc;
	(void)argv;
	t_cmd	cmd;
	int		i;
	i = 0;
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
	i = 0;
	free(cmd.input);
	return (0);
}

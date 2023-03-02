/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/02 13:22:25 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_signal(int sig)

{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static int	is_builtin(char *input)

{
	return (!ft_strncmp(input, "env", -1) || !ft_strncmp(input, "echo", -1));
}

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;

	(void)argc;
	(void)argv;
	create_env(&cmd, envp);
	signal(SIGINT, check_signal);
	while (1)
	{
		cmd.input = readline("Minishell: ");
		if (!(cmd.input[0] == '\0'))
			add_history(cmd.input);
		if (!strcmp(cmd.input, "exit"))
			break ;
		if (is_builtin(cmd.input))
			builtin_env(&cmd);
		else
			execution(&cmd);
		free(cmd.input);
	}
	free(cmd.input);
	cmd.status = 1;
	builtin_exit(&cmd);
	return (0);
}

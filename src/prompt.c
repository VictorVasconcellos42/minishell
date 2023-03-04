/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/04 16:21:14 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_builtin(char *input)

{
	if (!ft_strncmp(input, "env", 3))
		return (ENV);
	else if (!ft_strncmp(input, "exit", 4))
			return (EXIT);
	return (FALSE);
}

static void	check_input(char *input)

{
	if (!(input))
		handle_ctrl_backslash();
	else if (input[0] != '\0')
		add_history(input);
	return ;
}

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;

	(void)argc;
	(void)argv;
	create_env(&cmd, envp);
	handle_signal();
	while (1)
	{
		cmd.input = readline("Minishell: ");
		check_input(cmd.input);
		if (who_builtin(&cmd, is_builtin(cmd.input)) == FALSE)
			execution(&cmd);
		free(cmd.input);
	}
	free(cmd.input);
	builtin_exit(&cmd);
	return (0);
}

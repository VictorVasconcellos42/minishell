/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/13 18:36:02 by vde-vasc         ###   ########.fr       */
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
	(void)argc;
	(void)argv;
	init_minishell(&cmd);
	create_env(&cmd, envp);
	handle_signal();
	while (1)
	{
		cmd.input = readline("Minishell: ");
		cmd.cd = ft_split(cmd.input, ' ');
		build = is_builtin(cmd.input);
		check_input(cmd.input, &cmd);
		if (who_builtin(&cmd, build) == FALSE)
		{
			if (has_pipe(cmd.input, &cmd) == TRUE)
				pipes(&cmd, 0, 0);
			else
				execution(&cmd);
		}
		free(cmd.input);
	}
	builtin_exit(&cmd);
	return (0);
}

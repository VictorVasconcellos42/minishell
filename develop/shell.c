/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/13 13:26:40 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* int	main(int argc, char **argv, char **envp)

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
		cmd.token = lexer(&cmd);
		cmd.cd = ft_split(cmd.input, ' ');
		cmd.echo = ft_split(cmd.input, ' ');
		build = is_builtin(cmd.input);
		if (who_builtin(&cmd, build) == FALSE)
		{
			if (has_pipe(cmd.input, &cmd) == TRUE)
				executor(&cmd);
			else
				execution(&cmd);
		}
		free(cmd.input);
		free_matriz(cmd.cd);
	}
	builtin_exit(&cmd);
	return (0);
}
 */
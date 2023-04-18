/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/18 13:36:54 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	g_code = 0;

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
			if (!cmd.input || only_space(cmd.input))
				continue ;
			cmd.token = lexer(&cmd);
			if (!quote_handling(cmd.token))
			{
				clear_leak(&cmd);
				continue ;
			}
			if (!step_shell(&cmd))
				g_code = 1;
			restart_shell(&cmd);
		}
	}
	return (0);
}

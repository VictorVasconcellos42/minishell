/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/21 13:52:55 by vde-vasc         ###   ########.fr       */
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
//	int		build;
	char	**socorro;
	(void)argc;
	(void)argv;
	start_shell(&cmd, envp);
	handle_signal();
	while (1)
	{
		cmd.input = readline("Minishell: ");
		check_input(cmd.input, &cmd);
		cmd.token = lexer(&cmd);
		socorro = create_sentence(&cmd);
/* 		cmd.cd = ft_split(cmd.input, ' ');
		build = is_builtin(cmd.input);
		if (who_builtin(&cmd, build) == FALSE)
		{
			if (has_pipe(cmd.input, &cmd) == TRUE)
				pipes(&cmd, 0, 0);
			else
				execution(&cmd);
		} */
		free(cmd.input);
		//free_matriz(cmd.cd);
	}
	builtin_exit(&cmd);
	return (0);
}

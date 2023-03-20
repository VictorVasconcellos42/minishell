/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/20 11:34:41 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int matriz_len(char **str)

{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	type_var(char *str)

{
	if (ft_strnstr(str, ">>", -1))
		return (APP_INPUT);
	else if (ft_strnstr(str, "<<", -1))
		return (HERE_DOC);
	else if (!ft_strncmp(">", str, -1))
		return (R_OUTPUT);
	else if (!ft_strncmp("<", str, -1))
		return (R_INPUT);
	else if (!ft_strncmp("|", str, -1))
		return (PIPE);
	else
		return (WORD);
}

void	lexer(t_cmd *cmd, char **input)

{
	int		j = 0;
	cmd->token = malloc(sizeof(t_token) + (matriz_len(input) + 1));
	while (input[j])
	{
		cmd->token[j].value = ft_strdup(input[j]);
		cmd->token[j].type = type_var(input[j]);
		printf("TOKEN [%i]: [%s]\tVALUE: [%d]\n", j + 1, cmd->token[j].value, cmd->token[j].type);
		j++;
	}
}

/* static void	check_input(char *input, t_cmd *cmd)

{
	if (!(input))
	{
		control_free(cmd);
		handle_ctrl_d();
	}
	else if (input[0] != '\0')
		add_history(input);
	return ;
} */

int	main(int argc, char **argv, char **envp)

{
	t_cmd	cmd;
	char	**input;

	(void)argc;
	(void)argv;
	create_env(&cmd, envp);
	handle_signal();
	while (1)
	{
		cmd.input = readline("Minishell: ");
		input = ft_split(cmd.input, ' ');
		lexer(&cmd, input);
		if (who_builtin(&cmd, is_builtin(cmd.input)) == FALSE)
		{
			if (has_pipe(cmd.input, &cmd) == TRUE)
				pipes(&cmd);
			else
				execution(&cmd);
		}
		free(cmd.input);
	}
	builtin_exit(&cmd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:42:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/07 18:44:04 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



/* char	which_redirect(char *line)

{
	if (ft_strchr("><", line[i]))
} */

void	redirect(t_cmd *cmd)

{
	(void)cmd;
	return ;
}

void	pipes_and_red(t_cmd *cmd)

{
	(void)cmd;
	return ;
}

void	print_matriz(char **input)

{
	int i;

	i = 0;
	while (input[i])
		printf("ARG: [%s]", input[i++]);
}

void	remove_redirect(t_sentence sentence)

{
	int		i;
	int		origin;
	char	*temp;

	origin = 0;
	i = 0;
	while (sentence.args[i])
	{
		while (sentence.args[i] && is_output(sentence.args[i]))
			i += 2;
		if (sentence.args[i] == NULL)
			break ;
		temp = ft_strdup(sentence.args[i]);
		free(sentence.args[i]);
		sentence.args[origin++] = ft_strdup(temp);
		free(temp);
		i++;
	}
	sentence.args[origin] = NULL;
}

void	execute_sentence(t_sentence sentence, t_cmd *cmd)

{
	int	pid;
	int	backup;

	backup = dup(STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		if (sentence.input != STDIN_FILENO)
			dup2(sentence.input, STDIN_FILENO);
		if (sentence.output != STDOUT_FILENO)
			dup2(sentence.output, STDOUT_FILENO);
		remove_redirect(sentence);
		execve(sentence.args[0], sentence.args, cmd->env);
		perror(sentence.args[0]);
		exit(1);
	}
	dup2(backup, STDOUT_FILENO);
	waitpid(pid, NULL, 0);
}
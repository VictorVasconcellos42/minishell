/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:47:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/14 07:39:31 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_code(char *input, char **aux)

{
	free(input);
	free_matriz(aux);
}

void	start_shell(t_cmd *cmd, char **envp)

{
	init_minishell(cmd);
	if (envp == NULL)
		return ;
	create_env(cmd, envp);
}

void	init_minishell(t_cmd *cmd)

{
	cmd->path = NULL;
	cmd->token = NULL;
	cmd->sentence = NULL;
	cmd->c_pipes = 0;
}

int	**init_fd(t_sentence *sentence)

{
	int	i;
	int	**fd;

	i = 0;
	fd = malloc(sizeof(int *) * (how_many_sentences(sentence) - 1));
	while (i < how_many_sentences(sentence) - 1)
	{
		fd[i] = malloc(sizeof(int) * 2);
		remove_redirect(sentence[i++]);
	}
	return (fd);
}

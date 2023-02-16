/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/16 02:01:12 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		cmd.input = readline("minishell >> ");
		add_history(cmd.input);
		if (!strcmp(cmd.input, "exit"))
			break ;
		if (!strcmp(cmd.input, "env"))
		{
			cmd.env_size = len(envp);
			cmd.env = malloc(sizeof(char *) * cmd.env_size + 1);
			while (i < cmd.env_size - 1)
			{
				cmd.env[i] = envp[i];
				printf("%s\n", envp[i]);
				i++;
			}
			i = 0;
		}
		free(cmd.input);
	}
	i = 0;
	free(cmd.input);
	return (0);
}

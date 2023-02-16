/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/14 18:57:39 by vde-vasc         ###   ########.fr       */
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
	char *input;
	char **env;
	int		i;
	int		size;
	i = 0;
	while (1)
	{
		input = readline("minishell >> ");
		add_history(input);
		if (!strcmp(input, "exit"))
			break ;
		if (!strcmp(input, "env"))
		{
			size = len(envp);
			env = malloc(sizeof(char *) * size + 1);
			while (i < size - 1)
			{
				env[i] = envp[i];
				i++;
				printf("%s\n", envp[i]);
			}
			i = 0;
		}
		free(input);
	}
	i = 0;
	while (i < size - 1)
		free(env[i++]);
	return (0);
}

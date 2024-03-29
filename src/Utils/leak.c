/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:25:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/11 08:25:48 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_fd(int **input, int size)

{
	int	i;

	i = 0;
	while (i < size)
		free(input[i++]);
	free(input);
}

void	free_matriz(char **input)

{
	int	i;

	i = -1;
	while (input[++i])
		free(input[i]);
	free(input);
}

int	matriz_have_malloc(char **str)

{
	if (!str)
		return (FALSE);
	return (TRUE);
}

int	have_malloc(char *str)

{
	if (!str)
		return (FALSE);
	return (TRUE);
}

void	control_free(t_cmd *cmd)

{
	if (have_malloc(cmd->input) == TRUE)
		free(cmd->input);
	if (matriz_have_malloc(cmd->env) == TRUE)
		free_matriz(cmd->env);
	if (matriz_have_malloc(cmd->path) == TRUE)
		free_matriz(cmd->path);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:52 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/20 15:20:54 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"



char	**sentence(t_cmd *cmd)

{
	int			i;
	int			pipes;
	char		**matriz;

	i = 0;
	pipes = 0;
	matriz = has_pipe
	while (cmd->token[i].value != NULL)
	{
		if (cmd->token[i].type == PIPE)
		{
			pipes++;
			i++;
		}
		matriz[pipes] = ft_strjoin(matriz[pipes], cmd->token[i].value);
		matriz[pipes] = ft_strjoin_gnl(matriz[pipes], " ");
		i++;
	}
	matriz[pipes] = NULL;
	i = 0;
	while (matriz[i] != NULL)
	{
		printf("SENTENCA [%s]", matriz[i++]);
	}
	return (matriz);
}

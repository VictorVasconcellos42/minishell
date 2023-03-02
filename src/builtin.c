/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2023/03/02 15:57:02 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtin_env(t_cmd *cmd)

{
	int	i;

	i = 0;
	while (cmd->env[i])
		printf("%s\n", cmd->env[i++]);
}

void	builtin_exit(t_cmd *cmd)

{
	cmd->status = 1;
	printf("exit\n");
	if (cmd->status == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

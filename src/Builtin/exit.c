/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:20:19 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 15:20:43 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_exit(t_cmd *cmd)

{
	printf("exit\n");
	if (matriz_size(cmd->sentence->args) > 2)
	{
		if (!ft_str_isdigit(cmd->sentence->args[1]))
		{
			ft_printf("bash: exit: %s: numeric "
				"argument required\n", cmd->sentence->args[1]);
			exit(255);
		}
		ft_printf("bash: exit: too many arguments\n");
		g_code = 1;
		return ;
	}
	if (!(cmd->status == 0) && cmd->status < 255)
		exit(cmd->status);
	exit(EXIT_SUCCESS);
}

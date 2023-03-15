/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:47:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/15 08:24:57 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    init_minishell(t_cmd *cmd)

{
    cmd->exec = NULL;
    cmd->env = NULL;
    cmd->c_pipes = 0;
    cmd->path = NULL;
    cmd->pipex = NULL;
    cmd->token = NULL;
    cmd->sys_env = 0;
}
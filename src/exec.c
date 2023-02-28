/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 02:43:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/28 16:20:34 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	execution(t_cmd *exec)

{
	int	pid;

	pid = fork();
	exec->path = ft_split(exec->input, ' ');
	if (pid == 0)
	{
		execve(exec->path[0], exec->path, exec->env);
		exit(0);
	}
	else
		wait(0);
}

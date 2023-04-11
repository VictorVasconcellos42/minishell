/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_boolean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:43:12 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 22:48:58 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	has_pipe(char *string, t_cmd *cmd)

{
	int	i;

	i = 0;
	cmd->c_pipes = 0;
	while (string[i])
	{
		if (ft_strchr("|", string[i++]))
			cmd->c_pipes++;
	}
	if (cmd->c_pipes != 0)
		return (TRUE);
	return (FALSE);
}

int	is_pipes(int type)

{
	if (type == PIPE)
		return (TRUE);
	return (FALSE);
}

int	is_redirect(int type)

{
	if (type == HERE_DOC \
	|| type == APP_INPUT \
	|| type == R_INPUT \
	|| type == R_OUTPUT)
		return (TRUE);
	return (FALSE);
}

int	is_str_redirect(char *type)

{
	if (is_output(type) || \
	is_input(type) || \
	is_append(type) || \
	is_heredoc(type))
		return (TRUE);
	return (FALSE);
}

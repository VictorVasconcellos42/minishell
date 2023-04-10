/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_boolean.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:50:15 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 07:52:08 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	create_file(char *name, int type)

{
	if (type == APP_INPUT)
		return (open(name, O_CREAT | O_WRONLY | O_APPEND, 0644));
	else if (type == HERE_DOC)
		return (open(name, O_CREAT | O_WRONLY | O_RDONLY | O_APPEND, 0666));
	return (open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

int	is_output(char *type)

{
	if (!ft_strncmp(type, ">", 1))
		return (TRUE);
	return (FALSE);
}

int	is_input(char *type)

{
	if (!ft_strncmp(type, "<", 1))
		return (TRUE);
	return (FALSE);
}

int	is_append(char *type)

{
	if (!ft_strncmp(type, ">>", 2))
		return (TRUE);
	return (FALSE);
}

int	is_heredoc(char *type)

{
	if (!ft_strncmp(type, "<<", 2))
		return (TRUE);
	return (FALSE);
}

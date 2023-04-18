/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_boolean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:43:12 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/17 17:00:25 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

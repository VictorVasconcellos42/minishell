/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:28:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 08:46:26 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	easy_command(t_token *token)

{
	word(token);
	while (token[token->count].type == WORD)
		word(token);
}

int	check(t_token *token)

{
	if (token[token->count].type == WORD)
	{
		easy_command(token);
		if (is_redirect(token[token->count].type))
			return (redirects(token));
	}
	else if (is_redirect(token[token->count].type))
		return (redirects(token));
	else if (is_pipes(token[token->count].type))
		return (parser_error("|"));
	else
		pipeline(token);
	return (TRUE);
}

int	parser(t_token *token)

{
	token->count = 0;
	if (check(token))
		return (TRUE);
	return (FALSE);
}

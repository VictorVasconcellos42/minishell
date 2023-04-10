/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 07:38:58 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 08:01:34 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	file(t_token *token)

{
	if (token[token->count].type == WORD)
		token->count++;
	else
		return (parser_error("word"));
	return (TRUE);
}

void	pipeline(t_token *token)

{
	check(token);
	if (is_pipes(token[token->count].type))
	{
		token->count++;
		pipeline(token);
	}
}

int	word(t_token *token)

{
	if (token[token->count].type == WORD)
		token->count++;
	else
		return (FALSE);
	return (TRUE);
}

int	redirects(t_token *token)

{
	if (is_redirect(token[token->count].type))
	{
		token->count++;
		if (token[token->count].type == WORD)
			file(token);
		else
			return (parser_error("newline"));
	}
	else
		return (parser_error("'<' or '>'"));
	return (TRUE);
}

int	parser_error(char *text)

{
	printf("minishell: syntax error near unexpected token '%s'\n", text);
	//g_code = 258;
	return (FALSE);
}
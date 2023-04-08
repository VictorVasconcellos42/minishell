/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:28:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/08 17:13:24 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

int	file(t_token *token)

{
	if (token[token->count].type == WORD)
		token->count++;
	else
		return (parser_error("word"));
	return (TRUE);
}

int	parser_error(char *text)

{
	printf("minishell: syntax error near unexpected token '%s'\n", text);
	g_code = 258;
	return (FALSE);
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

void	easy_command(t_token *token)

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

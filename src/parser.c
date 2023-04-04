/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:28:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/04 15:46:43 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	file(t_token *token)

{
	if (token[token->count].type == WORD)
		token->count++;
	else
		return (parser_error("word"));
	return (TRUE);
}

int	word(t_token *token)

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
	//g_code = 258
	return (FALSE);
}

int	redirects(t_token *token)

{
	if (token[token->count].type == R_INPUT || \
		token[token->count].type == R_OUTPUT || \
		token[token->count].type == APP_INPUT || \
		token[token->count].type == HERE_DOC)
	{
		token->count++;
		if (token[token->count].type == WORD)
			file(token);
		else
			return (parser_error("file"));
	}
	else
		return (parser_error("'<' or '>'"));
	return (TRUE);
}

void	pipeline(t_token *token)

{
	check(token);
	if (token[token->count].type == PIPE)
	{
		token->count++;
		pipeline(token);
	}
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
		if (token[token->count].type == R_INPUT || \
			token[token->count].type == R_OUTPUT || \
			token[token->count].type == APP_INPUT || \
			token[token->count].type == HERE_DOC)
			return (redirects(token));
	}
	else if (token[token->count].type == PIPE)
		return (parser_error("|"));
	else if (token[token->count].type == R_INPUT || \
			token[token->count].type == R_OUTPUT || \
			token[token->count].type == APP_INPUT || \
			token[token->count].type == HERE_DOC)
		return (parser_error("newline"));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 11:10:41 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/13 13:32:29 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	which_quote(char quote)

{
	if (ft_strchr("'", quote))
		return (Q_SIMPLE);
	else if (ft_strchr("\"", quote))
		return (Q_DOUBLE);
	return (FALSE);
}

static int	double_quote(t_token *token, int pos, int start)

{
	int		i;
	char	*temp;
	int		reset;

	reset = start;
	i = 0;
	while (token[pos].value[reset] && \
	which_quote(token[pos].value[reset]) != Q_DOUBLE)
	{
		i++;
		reset++;
	}
	temp = malloc(sizeof(char) * i + 1);
	i = 0;
	while (token[pos].value[start] && \
	which_quote(token[pos].value[start]) != Q_DOUBLE)
		temp[i++] = token[pos].value[start++];
	temp[i] = '\0';
	free(token[pos].value);
	token[pos].value = temp;
	return (TRUE);
}

static int	simple_quote(t_token *token, int pos, int start)

{
	int		i;
	char	*temp;
	int		reset;
	char	*input;

	reset = start;
	input = token[pos].value;
	i = 0;
	while (input[reset] && (which_quote(input[reset]) != Q_SIMPLE))
	{
		i++;
		reset++;
	}
	temp = malloc(sizeof(char) * i + 1);
	i = 0;
	while (input[start] && which_quote(input[start]) != Q_SIMPLE)
		temp[i++] = token[pos].value[start++];
	temp[i] = '\0';
	free(token[pos].value);
	token[pos].value = temp;
	input = NULL;
	return (TRUE);
}

int	quote_handling(t_token *tokens)

{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (tokens[i].value)
	{
		j = -1;
		while (tokens[i].value[++j])
		{
			if (which_quote(tokens[i].value[j]) == Q_SIMPLE && !flag)
				flag = simple_quote(tokens, i, j + 1);
			else if (which_quote(tokens[i].value[j]) == Q_DOUBLE && !flag)
				flag = double_quote(tokens, i, j + 1);
		}
		if (only_space(tokens[i].value))
			return (FALSE);
		flag = 1;
		i++;
	}
	return (TRUE);
}

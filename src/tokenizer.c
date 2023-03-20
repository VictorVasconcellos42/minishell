/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 04:26:46 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/20 12:05:09 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Made by Magrão
// NO maintenance required
static void	*freedom(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array[i]);
	free(array);
	return (NULL);
}

static int	token_len(char const *string)
{
	char	quote;
	int		len;

	len = 0;
	quote = 0;
	while (*string == ' ')
		string++;
	while ((quote && *string) || (*string && *string != ' '))
	{
		if (!quote && (*string == '\'' || *string == '"'))
			quote = *string;
		else if (*string == quote && (*string == '\'' || *string == '"'))
			quote = 0;
		len++;
		string++;
	}
	return (len);
}

static int	count_tokens(char const *string)
{
	int	len;

	if (!*string)
		return (0);
	while (*string == ' ')
		string++;
	len = token_len(string);
	string += len;
	while (*string == ' ')
		string++;
	return (1 + count_tokens(string));
}

char	**tokenize(char const *string)
{
	int		tokens;
	int		token_index;
	char	**token_list;

	token_index = 0;
	tokens = count_tokens(string);
	token_list = malloc((tokens + 1) * sizeof(*token_list));
	if (!token_list)
		return (NULL);
	while (tokens--)
	{
		while (*string == ' ')
			string++;
		token_list[token_index] = ft_substr(string, 0, token_len(string));
		if (!token_list[token_index])
			return (freedom(token_list), NULL);
		string += token_len(string);
		while (*string == ' ')
			string++;
		token_index++;
	}
	token_list[token_index] = NULL;
	return (token_list);
}

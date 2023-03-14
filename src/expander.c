/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:24:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/14 08:55:50 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// TODO: Check leaks

static void *freedom(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array[i]);
	free(array);
	return (NULL);
}

int is_expandable(char *token)
{
	char *symbol_pointer;
	char next_char;

	symbol_pointer = ft_strchr(token, '$');
	next_char = *(symbol_pointer + 1);
	if (!symbol_pointer)
		return (0);
	if (!next_char)
		return (0);
	if (!ft_isalpha(next_char) && next_char != '_')
		return (0);
	// TODO: Check if symbol is between single quotes
	return (1);
}

int check_quotes(char *token)
{

	int i;
	char quote;

	i = 0;
	while (token[i] || token[i] != '\'' || token[i] == '"')
		i++;
	if (!token[i])
		return (0);
	quote = token[i];
	while (token[i] || token[i] != quote)
		i++;
	if (!token[i])
		return (0);
	return (quote);
}

char *remove_quotes_pair(char *token)
{
	char quote;
	char **split_table;
	char *clean_token;
	char *tmp;

	quote = check_quotes(token);
	if (!quote)
		return (token);
	split_table = ft_split(token, quote);
	tmp = ft_strjoin(split_table[0], split_table[1]);
	if (!tmp)
		return (freedom(split_table), NULL);
	clean_token = ft_strjoin(tmp, split_table[2]);
	if (!clean_token)
		return (free(tmp), freedom(split_table), NULL);
	return (free(tmp), freedom(split_table), clean_token);
}

char *expand_token(char *token)
{
	int end_pos;
	char *identifier;
	char *var_pointer;

	end_pos = 0;
	var_pointer = ft_strchr(token, '$') + 1;
	while (ft_isalnum(var_pointer[end_pos]) || var_pointer[end_pos] == '_')
		end_pos++;
	identifier = ft_substr(var_pointer, 0, end_pos);
	if (!identifier)
		return (NULL);
	return (identifier);
}

char *search_var(char *id, char **envp)
{
	int i;
	char *expanded;
	char *search_id;

	i = 0;
	search_id = ft_strjoin(id, "=");
	while (envp[i])
	{
		ft_printf("%s\n", id);
		ft_printf("%s\n", envp[i]);

		if (!ft_strncmp(search_id, envp[i], ft_strlen(id)))
		{
			expanded = ft_substr(envp[i], ft_strlen(id) + 1, ft_strlen(envp[i]));
			if (!expanded)
				return (NULL);
			free(search_id);
			return (expanded);
		}
		i++;
	}
	return (NULL);
}

void expand_tokens(char **tokens)
{
	int i;
	char *swap;
	i = 0;
	// TODO: Remove quotes
	while (tokens[i])
	{
		if (!is_expandable(tokens[i]))
			continue;
		swap = remove_quotes_pair(tokens[i]);
		if (!swap)
			return;
		free(tokens[i]);
		tokens[i] = swap;
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	// ft_printf("%s\n", search_var(expand_token(argv[1]), envp));
	ft_printf("%s\n", remove_quotes_pair(argv[1]));
}
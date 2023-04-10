/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:24:16 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 08:18:10 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*search_var(char *id, char **envp)
{
	int i;
	char *expanded;
	char *search_id;

	i = 0;
	if (*id == '?')
		return (ft_itoa(0));
	search_id = ft_strjoin(id, "=");
	while (envp[i])
	{
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

/* int	is_expandable(char *token)
{
	char *symbol_pointer;
	char next_char;

	symbol_pointer = ft_strchr(token, '$');
	next_char = *(symbol_pointer + 1);
	if (!symbol_pointer)
		return (0);
	if (!next_char)
		return (0);
	if (!ft_isalpha(next_char) && next_char != '_' && next_char != '?')
		return (0);
	return (1);
}

int	check_quotes(char *token)
{
	char	quote;
	char	*tmp;
	int		i;

	i = 0;
	tmp = 0;
	quote = 0;
	while (*token)
	{
		if (!quote && (*token == '\'' || *token == '"'))
		{
			if (!is_quote_closed(*token, token))
				return (0);
			quote = *token++;
		}
		else if (quote && (*token == quote))
		{
			quote = 0;
			token++;
		}
	}
}

char *remove_quotes_pair(char *token)
{
	char	*tmp;
	int		i;
	char	quote;
	char	*string;

	i = 0;
	quote = 0;
	tmp = malloc((ft_strlen(token) + 1) * sizeof(*tmp));
	if(!tmp)
		return (NULL);
	while (*token)
	{
		if (!quote && (*token == '\'' || *token == '"'))
		{
			quote = *token * is_quote_closed(quote, token);
			token++;
		}
		else if (quote && (*token == quote))
		{
			quote = 0;
			token++;
		}
		tmp[i++] = *token++;
	}
	tmp[i] = '\0';
	string = ft_strdup(tmp);
	if (!string)
		return (free(tmp), NULL);
	return (free(tmp), string);
}

// char *expand_token(char *token, char **envp)
// {
// 	int end_pos;
// 	char *identifier;
// 	char *var_pointer;
// 	char *expanded_token;

// 	end_pos = 0;
// 	var_pointer = ft_strchr(token, '$') + 1;
// 	if (*var_pointer == '?')
// 		end_pos++;
// 	else
// 	{
// 		while (ft_isalnum(var_pointer[end_pos]) || var_pointer[end_pos] == '_')
// 			end_pos++;
// 	}
// 	identifier = ft_substr(var_pointer, 0, end_pos);
// 	search_var(identifier, envp);
// 	if (!identifier)
// 		return (NULL);
		
// 	return (identifier);
// }

int	id_len(char *str)
{
	int	i;

	i = 0;
	if (is_expandable(str))
	{
		while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
			i++;
	}
	return (i);
}

char *expand_token(char *token, char **envp)
{
	int		i;
	char	quote;
	char	*tmp;
	//char	*result;

	i = 0;
	quote = 0;
	tmp = malloc((ft_strlen(token) + 1) * sizeof(*tmp));
	while (*token)
	{
		if (!quote && (*token == '\'' || *token == '"'))
		{
			quote = *token * is_quote_closed(quote, token);
			token++;
		}
		else if (quote && (*token == quote))
		{
			quote = 0;
			token++;
		}
		if (*token == '$' && quote != '\'')
		{
			search_var(token, envp);
		}
		tmp[i++] = *token++;
	}
}



void expand_tokens(char **tokens)
{
	int i;
	char *swap;
	i = 0;
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
} */

/*
int main(int argc, char **argv, char **envp)
{
	// ft_printf("%s\n", search_var(expand_token(argv[1]), envp));
	ft_printf("%s\n", remove_quotes_pair(argv[1]));
	//ft_printf("%s", get_indentifier(argv[1]));
}
*/

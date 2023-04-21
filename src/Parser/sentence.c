/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:52 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 16:43:35 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_redirect(t_sentence sentence)

{
	int		i;
	int		origin;
	char	*temp;

	origin = 0;
	i = 0;
	while (sentence.args[i])
	{
		while (sentence.args[i] && is_str_redirect(sentence.args[i]))
		{
			if (is_heredoc(sentence.args[i]))
				unlink(sentence.args[i + 1]);
			i += 2;
		}
		if (sentence.args[i] == NULL)
			break ;
		temp = ft_strdup(sentence.args[i]);
		free(sentence.args[i]);
		sentence.args[origin++] = ft_strdup(temp);
		free(temp);
		i++;
	}
	sentence.args[origin] = NULL;
}

static int	sentence_len(t_token *token)

{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (token[i].value)
	{
		if (is_pipes(token[i].type))
			count++;
		i++;
	}
	return (count);
}

static void	insert_value(t_sentence *sentence, int pos, char *temp)

{
	sentence[pos].input = STDIN_FILENO;
	sentence[pos].output = STDOUT_FILENO;
	sentence[pos].args = ft_split(temp, '\a');
}

t_sentence	*sentence_generator(t_token *token, int i, int count)

{
	t_sentence	*sentence;
	char		*temp;

	temp = ft_strdup("");
	sentence = ft_calloc(sizeof(t_sentence), (sentence_len(token) + 1));
	while (token[++i].value)
	{
		if (!is_pipes(token[i].type))
		{
			temp = ft_strjoin_gnl(temp, "\a");
			temp = ft_strjoin_gnl(temp, token[i].value);
		}
		else
		{
			insert_value(sentence, count, temp);
			count++;
			free(temp);
			temp = ft_strdup("");
		}
	}
	if (temp)
		insert_value(sentence, count++, temp);
	return (free(temp), sentence);
}

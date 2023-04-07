/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:52 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/07 17:24:55 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	sentence_len(t_token *token)

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

t_sentence	*sentence_generator(t_token *token, t_cmd *cmd)

{
	t_sentence	*sentence;
	char		*temp;
	int			i;
	int			count;
	
	(void)cmd;
	temp = ft_strdup("");
	sentence = malloc(sizeof(t_sentence) * (sentence_len(token) + 1));
	i = 0;
	count = 0;
	while (token[i].value)
	{
		if (!is_pipes(token[i].type))
		{
			temp = ft_strjoin(temp, " ");
			temp = ft_strjoin_gnl(temp, token[i].value);
		}
		else
		{
			sentence[count].input = STDIN_FILENO;
			sentence[count].output = STDOUT_FILENO;
			sentence[count++].args = ft_split(temp, ' ');
			free(temp);
			temp = ft_strdup("");
		}
		i++;
	}
	if (temp)
	{
		sentence[count].input = STDIN_FILENO;
		sentence[count].output = STDOUT_FILENO;
		sentence[count++].args = ft_split(temp, ' ');
		free(temp);
	}
	sentence[count].args = NULL;
	return (sentence);
}
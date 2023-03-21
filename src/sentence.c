/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sentence.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:26:52 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/20 16:27:52 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**split_sentence(t_cmd *cmd, int s_len, int len)

{
	char	**matriz;
	int		i;
	int		pos;
	int		count;
	char	*str;

	count = 0;
	i = 0;
	pos = 0;
	str = ft_strdup(cmd->input);
	matriz = ft_calloc(sizeof(char *), (s_len + 1));
	while (cmd->input[i] == ' ')
		i++;
	while (i <= len)
	{
		if (*str == '|' || (ft_strncmp(">", str, 1) && str[i + 1] == ' ') || (*str == '\0' && count != 0))
		{
			matriz[pos++] = ft_substr(cmd->input, i - count, count);
			count = 0;
		}
		else if (ft_strnstr(">>", str, 2) || ft_strnstr("<<", str, 2))
		{
			matriz[pos++] = ft_substr(cmd->input, i - count, count);
			count = 0;
		}
		else if (ft_strncmp("<", str, 1) && str[i + 1] == ' ')
		{
			matriz[pos++] = ft_substr(cmd->input, i - count, count);
			count = 0;
		}
		else
			count++;
		i++;
		str++;
	}
	return (matriz);
}

int	count_sentence(t_cmd *cmd, int len)

{
	int		i;
	char	*str;
	int		count_sentence;

	count_sentence = 0;
	str = ft_strdup(cmd->input);
	i = -1;
	while (*str == ' ')
		str++;
	while (++i < len)
	{
		if (*str == '|')
			count_sentence++;
		else if (ft_strnstr(">>", str, 2))
			count_sentence++;
		else if (ft_strnstr("<<", str, 2))
			count_sentence++;
		else if (ft_strncmp(">", str, 1) && str[i + 1] == ' ')
			count_sentence++;
		else if (ft_strncmp("<", str, 1) && str[i + 1] == ' ')
			count_sentence++;
		str++;
	}
	if (count_sentence != 0)
		count_sentence++;
	return (count_sentence);
}

char	**create_sentence(t_cmd *cmd)

{
	char	**sentence;
	int		s_len;
	int		str_len;

	str_len = ft_strlen(cmd->input);
	s_len = count_sentence(cmd, str_len);
	sentence = split_sentence(cmd, s_len, str_len);
	int i = -1;
	while (sentence[++i] != NULL)
		printf("Sentence: [%s]\n", sentence[i]);
	return (sentence);
}

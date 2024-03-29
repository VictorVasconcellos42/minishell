/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:18:55 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 16:50:22 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	type_var(char *str)

{
	if (is_append(str))
		return (APP_INPUT);
	else if (is_heredoc(str))
		return (HERE_DOC);
	else if (!ft_strncmp(str, ">", -1))
		return (R_OUTPUT);
	else if (!ft_strncmp(str, "|", 1) && (*str + 1 != '|'))
		return (PIPE);
	else if (!ft_strncmp(str, "<", -1))
		return (R_INPUT);
	else
		return (WORD);
}

t_token	*lexer(t_cmd *cmd)

{
	char	**tmp;
	t_token	*token;
	int		len;
	int		count;

	count = 0;
	tmp = tokenize(cmd->input);
	len = matriz_size(tmp);
	token = malloc(sizeof(t_token) * (len + 1));
	while (count < len)
	{
		token[count].value = ft_strdup(tmp[count]);
		token[count].type = type_var(tmp[count]);
		count++;
	}
	token[count].value = NULL;
	token[count].type = 0;
	free_matriz(tmp);
	return (token);
}

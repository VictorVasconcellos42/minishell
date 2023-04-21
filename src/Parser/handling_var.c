/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:33:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 19:47:00 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*str_joinchar(char *string, char set)

{
	int		len;
	char	*new;
	int		i;

	i = -1;
	len = ft_strlen(string) + 1;
	new = ft_calloc(sizeof(char), len + 1);
	while (string[++i])
		new[i] = string[i];
	new[i] = set;
	free(string);
	return (new);
}

static char	*insert_var(char *str, char **envp, int *pos, int len)

{
	int		start;
	char	*tmp;
	char	*path;
	char	*st;

	start = *pos + 1;
	st = ft_itoa(g_code);
	if (str[start] == '?')
	{
		*pos = start;
		return (st);
	}
	free(st);
	while (ft_isalnum(str[++*pos]))
		len++;
	path = ft_substr(str, start, len);
	tmp = search_var(path, envp);
	if (!tmp)
		tmp = ft_strdup("");
	free(path);
	--*pos;
	return (tmp);
}

t_token	handling(t_token token, char **envp)

{
	static int	j;
	char		*tmp;
	char		*exp;

	tmp = ft_strdup("");
	j = -1;
	while (token.value[++j])
	{
		if (token.value[j] == '$')
		{
			exp = insert_var(token.value, envp, &j, 0);
			tmp = ft_strjoin_gnl(tmp, exp);
			free(exp);
		}
		else
			tmp = str_joinchar(tmp, token.value[j]);
	}
	free(token.value);
	token.value = ft_strdup(tmp);
	free(tmp);
	return (token);
}

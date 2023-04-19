/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:33:27 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/19 14:47:05 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*str_joinchar(char *string, char set)

{
	int		len;
	char	*new;
	int		i;

	i = -1;
	if (!string)
		string = ft_strdup("");
	len = ft_strlen(string) + 1;
	new = ft_calloc(sizeof(char), len + 1);
	while (string[++i])
		new[i] = string[i];
	new[i] = set;
	free(string);
	return (new);
}

static char	*insert_var(char *str, char **envp, int *pos)

{
	int		start;
	char	*tmp;
	int		len;
	char	*path;

	start = *pos + 1;
	len = 0;
	if (str[start] == '?')
	{
		*pos = start;
		return (ft_itoa(g_code));
	}
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

void	handling(t_token token, char **envp)

{
	static int	j;
	char		*tmp;
	char		*exp;

	tmp = NULL;
	j = -1;
	tmp = ft_strdup("");
	while (token.value[++j])
	{
		if (token.value[j] == '$')
		{
			exp = insert_var(token.value, envp, &j);
			tmp = ft_strjoin_gnl(tmp, exp);
		}
		else
			tmp = str_joinchar(tmp, token.value[j]);
	}
	free(token.value);
	token.value = ft_strdup(tmp);
	free(tmp);
}

/* int	main(int argc, char **argv, char **envp)

{
	t_token *token;
	char	**tmp;
	char	*test;
	int		count;
	int		len;
	
	test = ft_strdup(argv[1]);
	tmp = tokenize(test);
	count = 0;
	len = matriz_size(tmp);
	token = ft_calloc(sizeof(t_token), (len + 1));
	while (count < len)
	{
		token[count].value = ft_strdup(tmp[count]);
		token[count].type = 0;
		count++;
	}
	token[count].value = NULL;
	token[count].type = 0;

	handling(token, envp);
	for (int i = 0; i < 2; i++)
		printf("TOKEN {%s}\n", token[i].value);
}
 */
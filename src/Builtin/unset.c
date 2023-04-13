/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:21:11 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/12 22:12:01 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_name(char *str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_isspace(char *str)

{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	unset(t_cmd *cmd, char *str)

{
	int		i;
	int		new_count;
	int		count;
	int		len_s;
	char	**new_envp;

	if (!is_valid_var(str))
		return ;
	i = ft_isspace(str);
	new_envp = malloc((matriz_size(cmd->env)) * sizeof(*new_envp));
	count = 0;
	new_count = 0;
	len_s = ft_name(str + i);
	while (cmd->env[count])
	{
		if (!ft_strncmp(cmd->env[count], str + i, len_s))
		{
			count++;
			continue ;
		}
		new_envp[new_count++] = ft_strdup(cmd->env[count++]);
	}
	new_envp[new_count] = NULL;
	free_matriz(cmd->env);
	cmd->env = new_envp;
}

int	builtin_unset(t_sentence sentence, t_cmd *cmd)

{
	int	i;

	i = 1;
	g_code = 0;
	while (sentence.args[i])
		unset(cmd, sentence.args[i++]);
	return (g_code);
}

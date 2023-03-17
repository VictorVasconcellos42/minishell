/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:07:05 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/17 15:34:19 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	var_name(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

int	is_present(t_cmd *cmd, char *var, int n)
{
	int	i;

	i = 0;
	while (cmd->env[i])
	{
		if (!ft_strncmp(cmd->env[i], var, n - 1))
			return (0);
		i++;
	}
	return (1);
}

void	export(t_cmd *cmd, char *new_var)

{
	int		count;
	char	**n_envp;
	int		n_present;

	n_envp = NULL;
	new_var = new_var + ft_isspace(new_var);
	count = 0;
	n_present = is_present(cmd, new_var, var_name(new_var));
	n_envp = malloc((matriz_size(cmd->env) + n_present + 1) * sizeof(*n_envp));
	while (cmd->env[count])
	{
		if (!ft_strncmp(cmd->env[count], new_var, var_name(new_var)))
		{
			n_envp[count++] = ft_substr(new_var, 0, ft_strlen(new_var));
			continue ;
		}
		n_envp[count] = ft_strdup(cmd->env[count]);
		count++;
	}
	if (n_present == 1)
		n_envp[count++] = ft_substr(new_var, 0, ft_strlen(new_var));
	n_envp[count] = NULL;
	free_matriz(cmd->env);
	cmd->env = n_envp;
}

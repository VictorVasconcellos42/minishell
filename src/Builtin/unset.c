/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:21:11 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 08:38:38 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_name(char *str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isspace(char *str)

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

/* int	main(int argc, char **argv, char **envp)

{
	char **envt;
	char **env;

	env = _env(envp);
	int len = matriz_size(env);
	int	i = 0;
	for (int j = 0; j < len; j++)
	{
		printf("%s\n", env[j]);
	}
	printf("---------------------------\n");
	envt = unset(argv[++i], env);
	while (argv[++i])
	{
		for (int j = 0; j < matriz_size(envt); j++)
			printf("%s\n", envt[j]);
		printf("-----------TESTE [%i]--------------\n", i);
		envt = unset(argv[i], envt);
	}
	for (int j = 0; j < matriz_size(envt); j++)
			printf("%s\n", envt[j]);
	free_matriz(envt);
} */

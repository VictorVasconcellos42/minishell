/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:18:17 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 22:48:32 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_concat(t_cmd *cmd, char *var, char *value)
{
	char	*input;

	input = ft_strjoin(var, "=");
	input = ft_strjoin_gnl(input, value);
	export(cmd, input);
	free(input);
	free(value);
}

//TODO: Error message when not found
int	cd(t_sentence cd, t_cmd *cmd)

{
	char	*old;
	char	*home;

	old = search_var("OLDPWD", cmd->env);
	home = search_var("HOME", cmd->env);
	export_concat(cmd, "OLDPWD", getcwd(NULL, 0));
	if (matriz_size(cd.args) == 1)
		chdir(home);
	else if (!ft_strncmp(cd.args[1], "-", -1))
	{
		chdir(old);
		printf("%s\n", old);
	}
	else
	{
		export_concat(cmd, "OLDPWD", getcwd(NULL, 0));
		if (chdir(cd.args[1]))
		{
			perror(cd.args[1]);
			g_code = 1;
		}
	}
	export_concat(cmd, "PWD", getcwd(NULL, 0));
	return (free(old), free(home), FALSE);
}

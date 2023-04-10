/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:18:17 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 08:15:45 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	export_concat(t_cmd *cmd, char *var, char *value)
{
	char	*input;

	input = ft_strjoin("export ", var);
	input = ft_strjoin_gnl(input, "=");
	input = ft_strjoin_gnl(input, value);
	export(cmd, input);
	free(input);
	free(value);
}

//TODO: Error message when not found
int	cd(char **cmd_table, t_cmd *cmd)

{
	int		i;
	char	*old;
	char	*home;

	i = -1;
	i++;
	old = search_var("OLDPWD", cmd->env);
	home = search_var("HOME", cmd->env);
	export_concat(cmd, "OLDPWD", getcwd(NULL, 0));
	if (matriz_size(cmd_table) == 1)
		chdir(home);
	else if (!ft_strncmp(cmd->cd[1], "-", -1))
	{
		chdir(old);
		printf("%s\n", old);
	}
	else
		chdir(cmd->cd[1]);
	export_concat(cmd, "PWD", getcwd(NULL, 0));
	return (free(old), free(home), 0);
}

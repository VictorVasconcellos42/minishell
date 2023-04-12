/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:14:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/12 13:50:54 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	how_many_sentences(t_sentence *sentence)

{
	int	i;

	i = 0;
	while (sentence[i].args)
		i++;
	return (i);
}

int	matriz_size(char **str)

{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_var(char *var)

{
	ft_putstr_fd("bash: export: ", 2);
	ft_putstr_fd(var, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
}

void	error_command(char *command)

{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}

int	ft_str_isdigit(char *str)

{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			puts("to aqui");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

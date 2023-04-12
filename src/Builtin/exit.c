/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:20:19 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/11 20:35:10 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	builtin_exit(t_sentence sentence)

{
	int	size;
	int	code;

	size = matriz_size(sentence.args);
	printf("exit\n");
	if (size == 2 && ft_str_isdigit(sentence.args[1]))
	{
		code = ft_atoi(sentence.args[1]);
		if (code > 255)
			exit(code - 256);
		exit(code);
	}
	else if (size > 2)
	{
		if (!ft_str_isdigit(sentence.args[1]))
		{
			ft_printf("bash: exit: %s: numeric "
				"argument required\n", sentence.args[1]);
			exit(255);
		}
		ft_printf("bash: exit: too many arguments\n");
		g_code = 1;
		return ;
	}
	exit(EXIT_SUCCESS);
}

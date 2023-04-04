/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:46:18 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/03 23:56:05 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_case(char *str)

{
	int	i;
	int	pipes;
	int	redirects;

	i = 0;
	pipes = 0;
	redirects = 0;
	while (str[i])
	{
		if (str[i] == '|')
			pipes++;
		else if (str[i] == '>' || str[i] == '<')
			redirects++;
		i++;
	}
	if (pipes && redirects)
		return (1);
	else if (pipes && !redirects)
		return (2);
	else if (!pipes && redirects)
		return (3);
	return (0);
}

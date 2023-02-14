/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:06:42 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/02/14 14:22:44 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)

{
	char *input;
	while (1)
	{
		input = readline("minishell >> ");
		add_history(input);
		if (!strcmp(input, "exit"))
			break ;
		free(input);
	}
	free(input);
	return (0);
}

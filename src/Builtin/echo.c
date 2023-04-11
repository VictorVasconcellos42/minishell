/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:44 by marolive          #+#    #+#             */
/*   Updated: 2023/04/11 06:36:29 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	next_line(int flag, int pos)

{
	if (flag == 1 && pos == 2)
		printf("\n");
	else if (flag == 1)
		printf("\n");
	return (0);
}

void	insert_line(char *line, int pos)

{
	printf("%s", line);
	if (line[pos + 1])
		printf(" ");
}

int	my_echo(t_sentence sentence, int flag, int i, int j)
{
	if (!sentence.args[++i])
		return (printf("\n"));
	if (!strncmp(sentence.args[i], "-n", 2))
		flag = 0;
	while (sentence.args[i])
	{
		while (!strncmp(sentence.args[i], "-n", 2) && flag == 0)
		{
			j = 0;
			while (sentence.args[i][++j])
			{
				if (!ft_strchr("n", sentence.args[i][j]))
				{
					insert_line(sentence.args[i], i);
					flag = 1;
					break ;
				}
			}
			if (sentence.args[i] == NULL)
				return (next_line(flag, i));
		}
		insert_line(sentence.args[i], i++);
	}
	return (next_line(flag, i));
}

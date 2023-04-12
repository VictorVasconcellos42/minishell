/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:44 by marolive          #+#    #+#             */
/*   Updated: 2023/04/11 23:01:41 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	printf_dollar(void)

{
	printf("STATUS CODE NOW: %d\n", g_code);
	g_code = 0;
	return (1);
}

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
	if (sentence.args[i][0] == '$' && sentence.args[i][1] == '?')
		return (printf_dollar());
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
		insert_line(sentence.args[i], i);
		i++;
	}
	return (next_line(flag, i));
}

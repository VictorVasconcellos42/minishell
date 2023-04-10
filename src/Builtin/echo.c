/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:44 by marolive          #+#    #+#             */
/*   Updated: 2023/04/10 08:15:49 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void my_echo(t_cmd *cmd)
{
    int i;
    int j;
    int flag;

    flag = 1;
    i = 1;
    j = 0;
    if (!cmd->echo[i])
        printf("\n");
    else
    {
        if(!strncmp(cmd->echo[i], "-n", 2))
            flag = 0;        
        while (cmd->echo[i])
        {
            while (!strncmp(cmd->echo[i], "-n", 2) && flag == 0)
            {
                j = 1;
                while (cmd->echo[i][j])
                {
                    if(!ft_strchr("n", cmd->echo[i][j]))
                    {
                        printf("%s", cmd->echo[i]);
                        if(cmd->echo[i + 1])
                            printf(" ");
                        flag = 1;
                        break ;
                    }
                    j++;
                }
                i++;
                if (cmd->echo[i] == NULL)
                {
                    if (flag == 1 && i == 2)
                        printf("\n");
                    return ;
                }
            }
            printf("%s", cmd->echo[i]);
            if(cmd->echo[i + 1])
                printf(" ");
            i++;
        }
        if(flag == 1)
            printf("\n");
    }
}
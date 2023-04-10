/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:48:44 by marolive          #+#    #+#             */
/*   Updated: 2023/04/10 12:24:14 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void my_echo(t_sentence sentence)
{
    int i;
    int j;
    int flag;

    flag = 1;
    i = 1;
    j = 0;
    if (!sentence.args[i])
        printf("\n");
    else
    {
        if(!strncmp(sentence.args[i], "-n", 2))
            flag = 0;        
        while (sentence.args[i])
        {
            while (!strncmp(sentence.args[i], "-n", 2) && flag == 0)
            {
                j = 1;
                while (sentence.args[i][j])
                {
                    if(!ft_strchr("n", sentence.args[i][j]))
                    {
                        printf("%s", sentence.args[i]);
                        if(sentence.args[i + 1])
                            printf(" ");
                        flag = 1;
                        break ;
                    }
                    j++;
                }
                i++;
                if (sentence.args[i] == NULL)
                {
                    if (flag == 1 && i == 2)
                        printf("\n");
                    return ;
                }
            }
            printf("%s", sentence.args[i]);
            if(sentence.args[i + 1])
                printf(" ");
            i++;
        }
        if(flag == 1)
            printf("\n");
    }
}
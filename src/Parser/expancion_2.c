/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expancion_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:26:28 by marolive          #+#    #+#             */
/*   Updated: 2023/04/14 08:38:19 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void dollar_n(t_cmd *cmd)
{
    char    *val;
    char    *tmp;
    char    *env;
    char    *pid;
    
    int i;
    int j;

    val = NULL;
    i = 0;
    j = 0;
    pid = ft_itoa(getpid());
    while (cmd->token->value[j])
    {
        if (cmd->token->value[j + 1] == '$')
        {
            tmp = pid;
            j += 2;
        }
        else
        {
            i = 0;
            if(ft_isalpha(cmd->token->value[j + 1]))
            {
                j++;
                while (ft_isalnum(cmd->token->value[j]))
                {
                    val[i] = cmd->token->value[j];
                    i++;
                    j++;
                }
                env = search_var(val, cmd->env);
                if (!env)
                    return ;
                tmp = env;
            }
        }
        //free(val);
    }
    
}
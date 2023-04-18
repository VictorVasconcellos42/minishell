/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:26:28 by marolive          #+#    #+#             */
/*   Updated: 2023/04/18 17:29:55 by marolive         ###   ########.fr       */
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

    i = 0;
    j = 0;
    val = ft_strdup("");
    tmp = ft_strdup("");
    pid = ft_itoa(getpid());
    while (cmd->token->value[j])
    {
        if (cmd->token->value[j + 1] == '$')
        {
            tmp = ft_strjoin_gnl(tmp, pid);
            j += 2;
            if (!cmd->token->value[j])
            {
                cmd->token->value = ft_strdup(tmp);
                break ;
            }
        }
        else
        {
            i = 0;
            if(ft_isalpha(cmd->token->value[j + 1]))
            {
                while (ft_isalnum(cmd->token->value[++j]))
                    val[i++] = cmd->token->value[j];
                val[i] = '\0';
                env = search_var(val, cmd->env);
                if (!env)
                    break ;
                else
                    tmp = ft_strjoin_gnl(tmp, env);
            }
            else
                break ;
        }
    }
    cmd->token->value = ft_strdup(tmp);
    free(tmp);
}
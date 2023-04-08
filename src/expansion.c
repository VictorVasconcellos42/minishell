/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:29:48 by marolive          #+#    #+#             */
/*   Updated: 2023/04/08 16:22:32 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    dolleta(t_cmd *cmd)
{
    char    *str;
    char    *tk;
    char    **val;
    int     i;
    char *pid;

    i = 0;
    pid = ft_itoa(getpid());    
    val = ft_split(cmd->token->value, '$');
    while (cmd->token->value[i + 1] == '$')
    {
        printf("pid: %s\n", pid);
        return ;
    }
    while (val[i])
    {
        str = ft_strdup(val[i]);
        tk = search_var(str, cmd->env);
        if(!tk)
            return ;
        printf("here: %s", tk);
        i++;
    }
    printf("\n");
}
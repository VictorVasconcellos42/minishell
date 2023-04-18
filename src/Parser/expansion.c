/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marolive <marolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:59:31 by marolive          #+#    #+#             */
/*   Updated: 2023/04/14 08:41:40 by marolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/* char *dollar_dollar(t_cmd *cmd)
{
    int j;
    char *pid;
    char *tmp;
    int size;

    j = 0;
    pid = ft_itoa(getpid());
    //size = ft_strlen(pid);
    //tmp = malloc(sizeof(char) * size);
    //printf("TMP: %s\n", tmp);
     if(cmd->token->value[j] == '$')
    {
        j += 2;
        if(cmd->token->value[j + 1] != '$')
            break ;
        //printf("\n*TMP 1: %s*\n",tmp);
    } 
    tmp = ft_strjoin(tmp, pid);
    return(tmp);
} */

void dollar(t_cmd *cmd)
{
    char    **val;
    char    *tmp;
    char    *env;
    char    *pid;
    
    int i;
    int j;

    i = 0;
    j = 0;
    val = ft_split(cmd->token->value, '$');
    pid = ft_itoa(getpid());
    if (cmd->token->value[j + 1] == '$')
    {
        tmp = pid;
        j += 2;
        if (!cmd->token->value[j])
            return ;
    }
    else
    {
        env = search_var(val[i], cmd->env);
        tmp = env;
        j += ft_strlen(val[i]) + 1;
        i++;
    }
    while(cmd->token->value[j])
    {
        if (cmd->token->value[j + 1] == '$')
        {
            tmp = ft_strjoin_gnl(tmp, pid);
            j += 2;
            if (!cmd->token->value[j])
                return ;
        }
        else
        {
            if (val[i])
            {
                env = search_var(val[i], cmd->env);
                if (!env)
                    return ;
                tmp = ft_strjoin_gnl(tmp, env);
                j += ft_strlen(val[i]) + 1;
                i++;
            }
        }
    }
    cmd->token->value = ft_strdup(tmp);
    free(tmp);
}

/* void    dolleta(t_cmd *cmd)
{
    char    *str;
    char    *env;
    char    **val;
    char    *pid;
    int     i;
    int     j;
    char    *tmp;

    i = 0;
    j = 1;

    pid = ft_itoa(getpid());
    val = ft_split(cmd->token->value, '$');
    //free(cmd->token->value);
    if (cmd->token->value[j] == '$')
    {
        tmp = pid;
        while (cmd->token->value[j] == '$')
        {
            //printf("-PID: %s- ", tmp);
            //free(cmd->token->value);
            //cmd->token->value = pid;
            if(cmd->token->value[j + 1] != '$')
                break ;
            j += 2;
            if(cmd->token->value[j] == '$')
            {
                tmp = ft_strjoin(tmp, pid);
                printf("\n*TMP 1: %s*\n", tmp);
            }
        }
        printf("\nTMP 1: {%s}\n", tmp);
    }
    else
    {
        j = 0;
        while (val[i])
        {
            str = ft_strdup(val[i]);
            env = search_var(str, cmd->env);
            if(!env)
                return ;
            if(tmp == NULL)
                tmp = env;
            else
            tmp = env;
            //free(cmd->token->value);
            //cmd->token->value = env;
            //temp = ft_strjoin(tmp, env);
            //printf("TOKEN22: %s", tmp);
            j += ft_strlen(val[i]);
            j++;
            i++;
            if(val[i] != NULL)
            {
                tmp = ft_strjoin(tmp, env);
                printf("\n*TMP 2: %s*\n", tmp);
                i++;
            }
        }
        printf("\nTMP 2: {%s}\n", tmp);
    }
    //printf("\nJOTA: %d\n", j);
    j ++;
    while (val[i])
    {
        str = ft_strdup(val[i]);
        env = search_var(str, cmd->env);
        if(!env)
            return ;
        if(tmp == NULL)
            tmp = env;
        else
        //tmp = env;
        tmp = ft_strjoin(tmp, env);
        //free(cmd->token->value);
        //cmd->token->value = env;
        //temp = ft_strjoin(tmp, env);
        //printf("TOKEN: %s", tmp);
        j += ft_strlen(val[i]);
        if (cmd->token->value[j] == '$')
        {
            printf("--J: %d--\n", j);
            //j++;
            while (cmd->token->value[j] == '$')
            {
                //tmp = pid;
                //printf("-PID: %s- ", tmp);
                //free(cmd->token->value);
                //cmd->token->value = pid;
                if(cmd->token->value[j + 1] != '$')
                    break ;
                tmp = ft_strjoin(tmp, pid);
                j += 2;
            }
            printf("\nTMP 4: {%s}\n", tmp);
        }
        i++;
        printf("\nTMP 3: {%s}\n", tmp);
    }
    printf("JOTAA: %d\n", j);
    //j++;
    if (cmd->token->value[j] == '$')
    {
        //printf("HERE\n");
        //j++;
        while (cmd->token->value[j] == '$')
        {
            //tmp = pid;
            tmp = ft_strjoin(tmp, pid);
            //printf("-PID: %s- ", tmp);
            //free(cmd->token->value);
            //cmd->token->value = pid;
            if(cmd->token->value[j + 1] != '$')
                break ;
            j += 2;
        }
        printf("\nTMP 4: {%s}\n", tmp);
    }
} */
    
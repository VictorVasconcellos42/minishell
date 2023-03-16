/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:25:25 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/16 18:29:54 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    free_matriz(char **input)

{
    int i;

    i = -1;
    while (input[++i])
        free(input[i]);
    free(input);
}

int matriz_have_malloc(char **str)

{
    if (!str)
        return (FALSE);
    return (TRUE);
}

int have_malloc(char *str)

{
    if (!str)
        return (FALSE);
    return (TRUE);
}

void    control_free(t_cmd *cmd)

{
    if (have_malloc(cmd->input) == TRUE)
        free(cmd->input);
    if (matriz_have_malloc(cmd->env) == TRUE)
        free_matriz(cmd->env);
    if (matriz_have_malloc(cmd->exec) == TRUE)
        free_matriz(cmd->exec);
    if (matriz_have_malloc(cmd->path) == TRUE)
        free_matriz(cmd->path);
}
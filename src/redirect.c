/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:48:20 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/07 17:18:47 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	create_file(char *name)

{
	return (open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

void	output_action(t_sentence *table, int pos, int i)

{
	int	file;
	
	file = create_file(table[pos].args[i + 1]);
	if (table[pos].output != STDOUT_FILENO)
		close(table[pos].output);
	table[pos].output = file;
}

int	is_output(char *type)

{
	if (!ft_strncmp(type, ">", 1))
		return (TRUE);
	return (FALSE);
}

int	is_input(char *type)

{
	if (!ft_strncmp(type, "<", 1))
		return (TRUE);
	return (FALSE);
}

int	is_append(char *type)

{
	if (!ft_strncmp(type, ">>", 2))
		return (TRUE);
	return (FALSE);
}

int	is_heredoc(char *type)

{
	if (!ft_strncmp(type, "<<", 2))
		return (TRUE);
	return (FALSE);
}

void	control_redirect(t_sentence *table)

{
	int	command;
	int	i;

	i = 0;
	command = 0;
	while (table[command].args)
	{
		i = 0;
		while (table[command].args[i])
		{
			if (is_append(table[command].args[i]))
				return ;
				// REDIRECIONAR E NAO APAGAR O CONTEUDO ANTIGO, A SAIDA DO COMANDO PARA UM ARQUIVO
			else if (is_heredoc(table[command].args[i]))
				// ABRIR UM PROMPT COM UMA PALAVRA CORINGA PARA PARA-LO.
				return ;
			else if (is_input(table[command].args[i]))
				return ;
				//REDIRECIONAR O CONTEUDO DE UM ARQUIVO PARA A ENTRADA DE UM COMANDO
			else if (is_output(table[command].args[i]))
			{
				output_action(table, command, i);
				//REDIRECIONAR O CONTEUDO DE UM COMANDO PARA DENTRO DE UM ARQUIVO
			}
			i++;
		}
		command++;
	}
}
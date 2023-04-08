/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:48:20 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/08 01:41:23 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	create_file(char *name, int type)

{
	if (type == APP_INPUT)
		return (open(name, O_CREAT | O_WRONLY | O_APPEND, 0644));
	else if (type == HERE_DOC)
		return (open(name, O_CREAT | O_WRONLY | O_RDONLY | O_APPEND, 0666));
	return (open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

void	output_action(t_sentence *table, int pos, int i)

{
	int	file;
	
	file = create_file(table[pos].args[i], R_OUTPUT);
	if (table[pos].output != STDOUT_FILENO)
		close(table[pos].output);
	table[pos].output = file;
}

int	append_action(t_sentence *table, int pos, int i)

{
	int file;

	file = create_file(table[pos].args[i], APP_INPUT);
	if (file == -1)
	{
		write(1, "bash: ", 6);
		perror(table[pos].args[i]);
		return (file);
	}
	else if (table[pos].output != STDOUT_FILENO)
		close(table[pos].output);
	table[pos].output = file;
	return (TRUE);
}

int	input_action(t_sentence *table, int pos, int i)

{
	int	file;

	file = open(table[pos].args[i], O_RDONLY);
	if (file == -1)
	{
		write(1, "bash: ", 6);
		perror(table[pos].args[i]);
		return (file);
	}
	else if (table[pos].input != STDIN_FILENO)
		close(table[pos].input);
	table[pos].input = file;
	return (TRUE);
}

void	heredoc_action(t_sentence *table, int pos, int i)

{
	char	*text;
	int		fake_file;
	int		len;

	fake_file = create_file(table[pos].args[i], HERE_DOC);
	text = readline("> ");
	len = ft_strlen(table[pos].args[i]);
	while (ft_strncmp(table[pos].args[i], text, len))
	{
		ft_putendl_fd(text, fake_file);
		free(text);
		text = readline("> ");
	}
	free(text);
	input_action(table, pos, i);
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

int	control_redirect(t_sentence *table)

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
			{	
				if (append_action(table, command, i + 1) == -1)
					return (FALSE);
			}
			else if (is_heredoc(table[command].args[i]))
				heredoc_action(table, command, i + 1);
			else if (is_input(table[command].args[i]))
			{
				if (input_action(table, command, i + 1) == -1)
					return (FALSE);
			}
			else if (is_output(table[command].args[i]))
				output_action(table, command, i + 1);
			i++;
		}
		command++;
	}
	return (TRUE);
}
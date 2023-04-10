/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 08:48:20 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/10 09:20:50 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	output_action(t_sentence *table, int pos, int i)

{
	int	file;
	
	file = create_file(table[pos].args[i], R_OUTPUT);
	if (table[pos].output != STDOUT_FILENO)
		close(table[pos].output);
	table[pos].output = file;
}

static int	append_action(t_sentence *table, int pos, int i)

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

static int	input_action(t_sentence *table, int pos, int i)

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

static void	heredoc_action(t_sentence *table, int pos, int i)

{
	char	*text;
	int		fake_file;
	int		len;

	fake_file = create_file(table[pos].args[i], HERE_DOC);
	text = readline("> ");
	if (!text)
		text = ft_strdup(table[pos].args[i]);
	len = ft_strlen(table[pos].args[i]);
	while (ft_strncmp(table[pos].args[i], text, len))
	{
		ft_putendl_fd(text, fake_file);
		free(text);
		text = readline("> ");
		if (!text)
		{
			free(text);
			text = ft_strdup(table[pos].args[i]);
		}
	}
	free(text);
	input_action(table, pos, i);
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
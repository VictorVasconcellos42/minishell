/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:17:06 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 13:25:02 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	child_exec(t_sentence sentence, t_cmd *cmd, int backup)

{
	child_signal();
	if (sentence.input != STDIN_FILENO)
	{
		dup2(sentence.input, STDIN_FILENO);
		close(sentence.input);
	}
	if (sentence.output != STDOUT_FILENO)
	{
		dup2(sentence.output, STDOUT_FILENO);
		close(sentence.output);
	}
	if (is_builtin(sentence.args[0]) != 0)
		the_builtin_executor(sentence, cmd);
	close(backup);
	remove_redirect(sentence);
	the_executor(sentence, cmd, -1);
}

void	fork_doc(t_sentence *table, int command, int i)

{
	heredoc_signal();
	heredoc_action(table, command, i + 1);
}

void	search_parth(t_sentence sentence, t_cmd *cmd)

{
	int		i;
	int		len;
	int		word_size;
	char	*temp;

	len = 0;
	i = ft_strlen(sentence.args[0]) - 1;
	while (sentence.args[0][i] != '/')
	{
		len++;
		i--;
	}
	word_size = ft_strlen(sentence.args[0]) - len - 1;
	cmd->size_cmd = word_size;
	temp = ft_substr(sentence.args[0], 0, word_size);
	chdir(temp);
	free(temp);
}

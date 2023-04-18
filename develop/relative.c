/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:17:06 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/17 17:24:33 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

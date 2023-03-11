/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:14:45 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/03/11 11:16:09 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	error_command(char *command)

{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": command not found\n", 2);
}
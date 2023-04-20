/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:40:22 by vde-vasc          #+#    #+#             */
/*   Updated: 2023/04/20 08:38:28 by vde-vasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sig_heredoc(int sig)

{
	if (sig == SIGINT)
	{
		signal(SIGINT, SIG_DFL);
		exit(1);
	}
	else
	{
		write(1, "> ", 2);
		ioctl(1, TIOCSTI, 1);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	handle_ctrl_d(void)

{
	ft_putstr("\x1b[1A");
	ft_putstr_fd("\033[11C", 1);
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

void	handle_ctrl_c(int sig)

{
	if (sig == SIGINT)
	{
		if (RL_ISSTATE(RL_STATE_READCMD))
			ioctl(1, TIOCSTI, "\n");
		else
			write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_code = 1;
	}
}

void	handle_signal(void)

{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	child_signal(void)

{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

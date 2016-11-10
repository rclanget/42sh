/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:37:47 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/10 14:11:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

#include "shell.h"
#include "command_line_termcaps.h"

t_info *save_info(t_info *info)
{
	static t_info *save;

	if (info)
		save = info;
	return (save);

}
void handling(int signal)
{
	t_info *info;

	(void)signal;
	info = save_info(NULL);
	if (info->term->cmd)
	{
		ft_bzero(info->term->cmd, BUFFER_SIZE);
		info->term->pos_c = 0;
	}
	ft_print(info->term->cmd ? "\n%s" : "\n", info->term->prompt);
}

int	ft_signal(int i)
{
	signal(SIGINT, i ? SIG_DFL : handling);
	return (0);
}

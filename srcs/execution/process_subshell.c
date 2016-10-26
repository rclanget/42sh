/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:26:43 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/25 19:49:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"
#include "execution.h"

t_tree				*self_node(t_info *info)
{
	static t_tree	tree;
	static int		set;

	if (!set)
	{
		ft_bzero(&tree, sizeof(t_tree));
		tree.elem = info->self;
		set++;
	}
	return (&tree);
}

int					process_subshell(t_info *info, t_tree *cmd)
{
	int				fdp[2];
	pid_t			pid;

	pipe(fdp);
	if (cmd->type == 9 && !(pid = fork()))
	{
		dup2(fdp[1], 1);
		close(fdp[0]);
		ft_putendl(cmd->elem);
		exit(0);
	}
	dup2(fdp[0], 0);
	close(fdp[1]);
	wait(0);
	execution_motor(info, self_node(info), 1);
	return (0);
}

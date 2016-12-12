/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:26:43 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/12 20:53:31 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"
#include "execution.h"
#include "hashmap.h"
#include "var.h"
#include "tools.h"

#ifdef __linux__
# include <wait.h>
#endif

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
	if (tree.cmd)
	{
		free_tab(tree.cmd);
		tree.cmd = NULL;
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
		save_fd(1);
		execution_motor(info, cmd->left, 1);
		exit(WEXITSTATUS(info->status));
	}
	if (cmd->type == 9)
	{
		waitpid(pid, &info->status, WUNTRACED);
		update_var(info, "?", ft_itoa2(WEXITSTATUS(info->status)));
	}
	return (0);
}

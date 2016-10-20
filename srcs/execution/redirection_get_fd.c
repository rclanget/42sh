/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:19:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/20 16:44:03 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

int			redirection_get_fd(t_tree *cmd)
{
	t_tree	*position_actuelle;
	int		fd_new_file;
	char	*new_str;

	new_str = NULL;
	position_actuelle = cmd;
	while (cmd && cmd->right && !(ft_strcmp(cmd->right->elem, ">")))
	{
		if (cmd->right->left)
			new_str = ft_strtrim(cmd->right->left->elem);
		fd_new_file = open(new_str, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		free(new_str);
		if (fd_new_file != -1)
		{
			close(fd_new_file);
			fd_new_file = -1;
		}
		cmd = cmd->right;
	}
	cmd = position_actuelle;
	while (cmd->right)
		cmd = cmd->right;
	return (open(cmd->elem, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
}


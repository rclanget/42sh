/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_get_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:19:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/21 14:10:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

// int			redirection_get_fd(t_tree *cmd)
// {
// 	t_tree	*position_actuelle;
// 	int		fd_new_file;
// 	char	*new_str;
//
// 	new_str = NULL;
// 	position_actuelle = cmd;
// 	while (cmd && cmd->right && !(ft_strcmp(cmd->right->elem, ">")))
// 	{
// 		if (cmd->right->left)
// 			new_str = ft_strtrim(cmd->right->left->elem);
// 		fd_new_file = open(new_str, O_WRONLY | O_TRUNC | O_CREAT,
// 			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
// 		free(new_str);
// 		if (fd_new_file != -1)
// 		{
// 			close(fd_new_file);
// 			fd_new_file = -1;
// 		}
// 		cmd = cmd->right;
// 	}
// 	cmd = position_actuelle;
// 	while (cmd->right)
// 		cmd = cmd->right;
// 	return (open(cmd->elem, O_WRONLY | O_TRUNC | O_CREAT,
// 			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
// }

#include <stdio.h>

int			redirection_get_fd(t_tree *cmd)
{
	int		i;
	t_tree	*list[20];

	i = 0;
	while (cmd->right)
	{
		if (cmd->type == 5 && cmd->right->type)
		{
			list[i] = cmd->right->left;
			printf("%s\n", list[i]->elem);
			i++;
		}
		else if (cmd->type == 5)
		{
			list[i] = cmd->right;
			printf("%s\n", list[i]->elem);
			i++;
		}
		cmd = cmd->right;
	}
	return 0;
}

			// 
			// echo > f1 < f2 > f3
			// 		>
			// echo 1		<
			// 		f1		>
			// 			f2		f3

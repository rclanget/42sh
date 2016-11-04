/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:28:36 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/04 12:46:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

int			builtin_exit(t_info *info, t_tree *cmd)
{
	info->status = ft_atoi(cmd->cmd[1]);
	info->stop = 1;
	return (0);
}

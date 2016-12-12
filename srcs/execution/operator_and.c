/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_and.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:48:33 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:15 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"

int				operator_and(t_info *info, t_tree *cmd)
{
	if (!execution_motor(info, cmd->left, 1))
	{
		save_fd(0);
		return (info->stop ? 0 : execution_motor(info, cmd->right, 1));
	}
	else
		return (1);
}

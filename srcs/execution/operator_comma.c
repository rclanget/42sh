/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_comma.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:17:24 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:38 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"

int				operator_comma(t_info *info, t_tree *cmd)
{
	if (cmd && cmd->left)
		execution_motor(info, cmd->left, 1);
	save_fd(0);
	if (cmd && cmd->right && !info->stop)
		execution_motor(info, cmd->right, 1);
	return (0);
}

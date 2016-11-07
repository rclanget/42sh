/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:23:12 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 11:21:14 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"

int			operator_or(t_info *info, t_tree *cmd)
{
	if (!execution_motor(info, cmd->left, 1))
	{
		return (0);
	}
	save_fd(0);
	return (execution_motor(info, cmd->right, 1));
}

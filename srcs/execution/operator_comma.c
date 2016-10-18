/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_comma.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:17:24 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 11:20:55 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int				operator_comma(t_info *info, t_tree *cmd)
{
	if (cmd && cmd->left)
		execution_motor(info, cmd->left, 1);
	if (cmd && cmd->right)
		execution_motor(info, cmd->right, 1);
	return (0);
}

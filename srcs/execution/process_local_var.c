/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_local_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 19:26:43 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/12 11:37:52 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "var.h"

#ifdef __linux__
# include <wait.h>
#endif

int			process_local_var(t_info *info, t_tree *cmd)
{
	update_var(info, cmd->left->elem, cmd->right->elem);
	return (0);
}

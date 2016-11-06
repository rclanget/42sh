/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_apply_fd_agreg.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:25:03 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 18:35:49 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "parser.h"
#include "execution.h"

void			apply_fd_agreg(t_tree *cmd)
{
	t_tree		*node;

	node = cmd;
	while (node->right && node->type)
	{
		if (node->right->type)
			node->right->left->cmd = redirection_agreg(cust_split(node->right->left->elem));
		else
			node->right->cmd = redirection_agreg(cust_split(node->right->elem));
		node = node->right;
	}
}

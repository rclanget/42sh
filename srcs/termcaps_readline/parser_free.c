/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 15:17:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/02 15:19:53 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "parser.h"
#include "hashmap.h"

void				*parser_free_cmd(t_tree *cmd)
{
	if (cmd)
	{
		parser_free_cmd(cmd->right);
		parser_free_cmd(cmd->left);
		free_tab(cmd->cmd);
		free(cmd->elem);
		free(cmd);
	}
	return (NULL);
}

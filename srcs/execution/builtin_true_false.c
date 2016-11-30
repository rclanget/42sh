/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_true_false.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:54:59 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/30 14:37:09 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			builtin_false(t_info *info, t_tree *cmd)
{
	(void)info;
	(void)cmd;
	return (1);
}

int			builtin_true(t_info *info, t_tree *cmd)
{
	(void)info;
	(void)cmd;
	return (0);
}

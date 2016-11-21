/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_true_false.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:54:59 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/21 18:03:57 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			builtin_false(t_info * info, t_tree *cmd)
{
	(void)info;
	(void)cmd;
	return (1);
}

int			builtin_true(t_info * info, t_tree *cmd)
{
	(void)info;
	(void)cmd;
	return (0);
}

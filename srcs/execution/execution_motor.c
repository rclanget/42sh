/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_motor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:18:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/31 10:46:09 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "execution.h"
#include "libft.h"
#include "tools.h"

#include <unistd.h>

int (*p[])(t_info *x, t_tree *y) = {\
			NULL,\
			&operator_comma, \
			&operator_and,\
			&operator_or, \
			&operator_pipe, \
			&redirection_right, \
			&redirection_left, \
			&redirection_dright, \
			&redirection_dleft,
			&process_subshell};

int				wich_operator(char *op)
{
	if (*op == '>')
		return ((*(op + 1)) ? 6 : 5);
	if (*op == '<')
		return ((*(op + 1)) ? 8 : 7);
	if (*op == '&' && *(op + 1))
		return (1);
	if (*op == '|')
		return ((*(op + 1)) ? 2 : 4);
	return (3);
}

int				execution_motor(t_info *info, t_tree *cmd, int wait)
{
	char		*tmp;

	tmp = apply_magicquote(info, cmd->elem);
	cmd->cmd = cust_split(tmp);
	ft_free_them_all(1, tmp);
	if (cmd && cmd->cmd)
	{
		if (!cmd->type)
			return (execution_command(info, cmd, wait));
		else
			return (p[cmd->type](info, cmd));
	}
	return (0);
}

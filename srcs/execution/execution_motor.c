/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_motor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:18:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/16 18:29:17 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "execution.h"
#include "libft.h"
#include "tools.h"
#include "var.h"

#include <unistd.h>

int (*g_p[])(t_info *x, t_tree *y) =
{\
	NULL,\
	&operator_comma, \
	&operator_and,\
	&operator_or, \
	&operator_pipe, \
	&redirection_right, \
	&redirection_left, \
	&redirection_dright, \
	&redirection_dleft, \
	&process_subshell, \
	&process_local_var
};

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
	char		*tmp1;

	cmd->elem = parser_tild(info, cmd->elem);
	tmp = parse_var(info, ft_strdup(cmd->elem));
	tmp1 = apply_magicquote(info, tmp, cmd->type);
	cmd->cmd = redirection_agreg(cust_split(tmp1));
	ft_free_them_all(2, &tmp, &tmp1);
	if (cmd && cmd->cmd && cmd->cmd[0])
	{
		if (!cmd->type)
			return (execution_command(info, cmd, wait));
		return (g_p[cmd->type](info, cmd));
	}
	return (0);
}

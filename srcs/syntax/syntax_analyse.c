/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 17:47:05 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/15 20:18:09 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "syntax.h"

int (*g_checker[])(t_tree *y) =
{\
	&syntax_comma,\
	&syntax_logical, \
	&syntax_subshell
};

int				syntax_comma(t_tree *cmd)
{
	if (!syntax_check(cmd->left, 0))
		return (0);
	return ((!cmd->right) ? 1 : syntax_check(cmd->right, 0));
}

int				syntax_logical(t_tree *cmd)
{
	int	ret;
	ret = syntax_check(cmd->left, 0) && syntax_check(cmd->right, 0);
	if (ret && (2 == cmd->type) && !cmd->left->type && cmd->left->elem[ft_strlen(cmd->left->elem) - 1] == '&')
		ret = 0;
	return (ret);
}

int				syntax_subshell(t_tree *cmd)
{
	(void)cmd;
	return (1);
}

int				syntax_family(int type)
{
	int ret;

	ret = 0;
	if (type == 1)
		ret = 0;
	else if (2 <= type && type <= 8)
		ret = 1;
	else if (type == 9)
		ret = 2;
	return (ret);
}

int				syntax_check(t_tree *cmd, int reset)
{
	int			ret;
	static int	status;

	ret = 0;
	if (reset)
		status = 0;
	if (cmd)
	{
		if (!cmd->type)
			ret = 1;
		else if (!(ret = g_checker[syntax_family(cmd->type)](cmd)) && !status++)
			ft_fdprint(2, "42sh: parse error near \'%s\'\n", cmd->elem);
	}
	return (ret);
}

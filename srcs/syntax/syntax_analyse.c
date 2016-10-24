/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 17:47:05 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/24 16:13:44 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "syntax.h"

int (*checker[])(t_tree *y) = {\
			&syntax_comma,\
			&syntax_logical, \
			&syntax_redir};

int		syntax_comma(t_tree *cmd)
{
	if (!syntax_check(cmd->left, 0))
		return (0);
	return ((!cmd->right) ? 1 : syntax_check(cmd->right, 0));
}

int		syntax_logical(t_tree *cmd)
{
	return (syntax_check(cmd->left, 0) && syntax_check(cmd->right, 0));
}

int		syntax_redir(t_tree *cmd)
{
	return (syntax_check(cmd->left, 0) && syntax_check(cmd->right, 0));
}

int		syntax_family(int type)
{
	int ret;

	ret = 0;
	if (type == 1)
		ret = 0;
	else if (2 <= type &&  type <= 4)
		ret = 1;
	else if (5 <= type && type <= 9)
		ret = 2;
	return ret;
}

int		syntax_check(t_tree *cmd, int reset)
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
		else if (!(ret = checker[syntax_family(cmd->type)](cmd)) && !status++)
			ft_print("42sh: parse error near \'%s\'\n", cmd->elem);
	}
	return (ret);
}

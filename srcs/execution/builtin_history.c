/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:49:43 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/01 20:24:52 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "history.h"
#include "builtin_history.h"
#include "libft.h"
#include "tools.h"

#define OPTS "cdanrwps"

int			check_options(int option)
{
	int		ret;
	int		act;

	ret = 1;
	act = 0;
	if ((option & OPT_C) && ++act)
		ret = 2;
	if ((option & OPT_D) && ++act)
		ret = 3;
	if (((option & OPT_A) || (option & OPT_N) || (option & OPT_R) ||
		(option & OPT_W)) && ++act)
		ret = 4;
	if (((option & OPT_P) || (option & OPT_S)) && ++act)
		ret = 5;
	return ((act > 1) ? 0 : ret);
}

static int	error(void)
{
	ft_putendl_fd("history: bad options\nhistory: usage: history [-c] [-d o"\
	"ffset] [n] or history -anrw [filename] or history -ps arg [arg...]", 2);
	return (1);
}

int			builtin_history(t_info *info, t_tree *cmd)
{
	int		option;
	int		i;
	char	**av;

	option = 0;
	if ((i = ft_option(ft_tablen(cmd->cmd), cmd->cmd, OPTS, &option)) == -1)
		return (error());
	av = cmd->cmd + i;
	if ((i = check_options(option)))
	{
		if (i == 1)
			history_base(info, av);
		else if (i == 2)
			history_clear(info, av);
		else if (i == 3)
			history_deloffset(info, av);
		else if (i == 4)
			history_file(&(*info), av, option);
		else if (i == 5)
			history_substitute(info, av, option);
	}
	else
		return (error());
	return (0);
}

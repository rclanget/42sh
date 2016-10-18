/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 10:50:31 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:24:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"

#define OPT_N	0x001

int			builtin_echo(t_info *info, t_tree *cmd)
{
	int		i;
	int		option;
	char	**tab;

	i = 0;
	(void)info;
	tab = cmd->cmd;
	if ((i = ft_option(0, tab, "n", &option)) < 0)
		return (1);
	tab += i;
	i = -1;
	while (tab[++i])
		ft_print(i ? " %s" : "%s", tab[i]);
	if (!(option & OPT_N))
		ft_print("\n");
	return (0);
}

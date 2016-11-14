/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 22:51:52 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/10 20:59:48 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"
#include "parser.h"
#include "history.h"

#include <unistd.h>

void		show_tree(t_tree *tree)
{
	if (tree)
	{
		show_tree(tree->left);
		ft_print("{%d;%s}\n", tree->type, tree->elem);
		show_tree(tree->right);
	}
}

char		*return_string(t_termcaps *term)
{
	int		len;

	if ((len = ft_strlen(term->cmd)) != term->pos_c)
		move_cursor(term->capa, term->pos_c, ft_strlen(term->prompt), len);
	ft_putstr("\n");
	return (ft_strdup(term->cmd));
}

char		*termcaps_loop(t_info *info)
{
	int		ret;
	long	chr;
	char	*returned;

	chr = 0;
	set_temporary_hist(info, 1);
	while ((ret = read(0, &chr, sizeof(chr))) > 0)
	{
		if ((chr == NL) ||
			(chr == CTRL_D && !ft_strlen(info->term->cmd) && (ret = -1) == -1))
			break ;
		termcaps_handle_keyboard(info, chr);
		chr = 0;
	}
	returned = (ret != -1) ? return_string(info->term) : NULL;
	set_temporary_hist(info, 0);
	return (returned);
}

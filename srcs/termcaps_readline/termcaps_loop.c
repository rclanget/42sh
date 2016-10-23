/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 22:51:52 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/23 20:51:30 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"
#include "libft.h"
#include "parser.h"

#include <unistd.h>

void 		show_tree(t_tree *tree)
{
	if (tree)
	{
		show_tree(tree->left);
		ft_print("{%d;%s}\n", tree->type, tree->elem);
		show_tree(tree->right);
		// free(tree->elem);
		// free(tree);
	}
}

char        *return_string(t_termcaps *term)
{
	int		len;

	if ((len = ft_strlen(term->cmd)) != term->pos_c)
		move_cursor(term->capa, term->pos_c, ft_strlen(term->prompt), len);
	ft_putstr("\n");
	return (ft_strdup(term->cmd));
}

char        *termcaps_loop(t_info *info)
{
	int                 ret;
	long                chr;

	chr = 0;
	while ((ret = read(0, &chr, sizeof(chr))) > 0)
	{
		if ((chr == NL) || (chr == CTRL_D && (ret = -1) == -1))
			break;
		termcaps_handle_keyboard(info, chr);
		chr = 0;
	}
	termcaps_save(0);
	return ((ret == -1) ? NULL : return_string(info->term));
}

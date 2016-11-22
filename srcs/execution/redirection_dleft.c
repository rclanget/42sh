/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_dleft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:24:07 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/21 17:27:26 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "redirection_dleft.h"
#include "libft.h"

#include <stdlib.h>

int		modif_tree(t_tree *tree)
{
	t_tree		*n;
	t_tree		*tmp;
	char		*f_name;

	while (tree && (n = find_dleft(tree)) != NULL)
	{
		f_name = dleft_redirection(get_delimit(n), !ft_strcmp(n->elem, "<<-"));
		if ((n->right && !(n->right->type)) ||
		(n->right->left && !(n->right->left->type)))
		{
			n->type = 6;
			tmp = (n->right && !(n->right->type)) ? n->right : n->right->left;
			if (tmp->elem)
				free(tmp->elem);
			tmp->elem = f_name;
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_dleft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <gdeguign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:24:07 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/14 15:03:01 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "redirection_dleft.h"

#include <stdlib.h>

int		modif_tree(t_tree *tree)
{
	t_tree		*un_noeud;
	char		*nom_fichier_temp;

	if (!tree)
		return (1);
	while ((un_noeud = find_dleft(tree)) != NULL)
	{
		nom_fichier_temp = dleft_redirection(get_delimit(un_noeud), 0);
		if (un_noeud->right && !(un_noeud->right->type))
		{
			un_noeud->type = 6;
			if (un_noeud->right->elem)
				free(un_noeud->right->elem);
			un_noeud->right->elem = nom_fichier_temp;
		}
		else if (un_noeud->right->left && !(un_noeud->right->left->type))
		{
			un_noeud->type = 6;
			if (un_noeud->right->left->elem)
				free(un_noeud->right->left->elem);
			un_noeud->right->left->elem = nom_fichier_temp;
		}
	}
	return (1);
}

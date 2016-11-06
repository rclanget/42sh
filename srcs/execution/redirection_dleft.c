/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_dleft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <gdeguign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 18:24:07 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/06 16:28:56 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "tools.h"
#include <fcntl.h>

#define BUFF_SIZE 1

int get_next_line(int fd, char **line);

char	*ft_fichier_temp(int tmp)
{
	char		*nom_fichier_temp;
	char		*itoa_tmp;

	itoa_tmp = ft_itoa(tmp);
	nom_fichier_temp = ft_strjoin_custom("/tmp/shell_tmp", itoa_tmp);
	ft_strdel(&itoa_tmp);
	return (nom_fichier_temp);
}

void	sub_redirection_dleft(const char *d, int fd)
{
	char		*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!(ft_strcmp(d, line)))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
		ft_putstr("< ");
	}
}

char	*dleft_redirection(const char *delimiteur, int reinit)
{
	static int	tmp = 1;
	int			fd;
	char		*nom_fichier_temp;

	if (reinit)
	{
		tmp = 1;
		return (NULL);
	}
	nom_fichier_temp = ft_fichier_temp(tmp);
	fd = open(nom_fichier_temp, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (isatty(0))
	{
		ft_putstr("< ");
		sub_redirection_dleft(delimiteur, fd);
	}
	close(fd);
	tmp++;
	return (nom_fichier_temp);
}

t_tree	*find_dleft(t_tree *tree)
{
	t_tree		*tmp;

	tmp = NULL;
	if (tree)
	{
		if (tree->type == 8)
			return (tree);
		else if ((tmp = find_dleft(tree->left)))
			return (tmp);
		else if ((tmp = find_dleft(tree->right)))
			return (tmp);
	}
	return (NULL);
}

char	*get_delimit(t_tree *un_noeud)
{
	char		*delimit;

	delimit = NULL;
	if (un_noeud->right && !(un_noeud->right->type))
	{
		if (un_noeud->right->elem)
			delimit = un_noeud->right->elem;
	}
	else if (un_noeud->right->left && !(un_noeud->right->left->type))
	{
		if (un_noeud->right->left->elem)
			delimit = un_noeud->right->left->elem;
	}
	return (delimit);
}

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

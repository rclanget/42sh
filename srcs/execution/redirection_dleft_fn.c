/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_dleft_fn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:57:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/30 14:46:07 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "get_next_line.h"
#include "parser.h"

#include <fcntl.h>

char	*ft_fichier_temp(int tmp)
{
	char		*nom_fichier_temp;
	char		*itoa_tmp;

	itoa_tmp = ft_itoa(tmp);
	nom_fichier_temp = ft_strjoin_custom("/tmp/shell_tmp", itoa_tmp);
	ft_strdel(&itoa_tmp);
	return (nom_fichier_temp);
}

void	sub_redirection_dleft(const char *d, int fd, int option)
{
	char		*line;
	char		*tmp;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (!(ft_strcmp(d, line)))
		{
			free(line);
			break ;
		}
		tmp = line;
		while (option && *tmp == '\t')
			tmp++;
		ft_putendl_fd(tmp, fd);
		free(line);
		ft_putstr("< ");
	}
}

char	*dleft_redirection(const char *delimiteur, int option)
{
	static int	tmp = 1;
	int			fd;
	char		*nom_fichier_temp;

	nom_fichier_temp = ft_fichier_temp(tmp);
	fd = open(nom_fichier_temp, O_WRONLY | O_TRUNC | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (isatty(0))
	{
		ft_putstr("< ");
		sub_redirection_dleft(delimiteur, fd, option);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_dleft.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:58:55 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 14:59:28 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_DLEFT_H
#define REDIRECTION_DLEFT_H

char	*ft_fichier_temp(int tmp);
void	sub_redirection_dleft(const char *d, int fd);
char	*dleft_redirection(const char *delimiteur, int reinit);
t_tree	*find_dleft(t_tree *tree);
char	*get_delimit(t_tree *un_noeud);

#endif

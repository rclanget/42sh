/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 19:16:28 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/23 20:08:31 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_H
# define SYNTAX_H

# include "parser.h"

int		syntax_comma(t_tree *cmd);
int		syntax_logical(t_tree *cmd);
int		syntax_redir(t_tree *cmd);
int		syntax_check(t_tree *cmd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:33:11 by zipo              #+#    #+#             */
/*   Updated: 2016/11/22 23:50:19 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

#include    "shell.h"
#include    "alias_struct.h"

void        update_var(t_info *info, char *init, char *replace);
t_alias		*search_var(t_info *info, char *var);
void		remove_var(t_info *info, char *var);
void	    add_var(t_info *info, char *var, char *content);

char		*parse_var(t_info *info, char *cmd);

#endif

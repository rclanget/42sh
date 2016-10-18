/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:55:13 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 12:51:26 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALIAS_H
# define ALIAS_H

# include "shell.h"
# include "alias_struct.h"

void		add_alias(t_info *info, char *var, char *content);
void		remove_alias(t_info *info, char *var);
t_alias		*search_alias(t_info *info, char *var);
void		update_alias(t_info *info, char *init, char *replace);
char		*check_alias(t_info *info, char *init);

#endif

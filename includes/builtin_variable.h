/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_variable.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:11:47 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/22 17:12:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_VARIABLE_H
# define BUILTIN_VARIABLE_H

void		add_var(t_info *info, char *var, char *content);
void		remove_var(t_info *info, char *var);
t_alias		*search_var(t_info *info, char *var);
void		update_var(t_info *info, char *init, char *replace);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:54:11 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 16:32:08 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "shell.h"

typedef struct			s_history
{
	char				*cmd;
	int					n;
	struct s_history	*next;
	struct s_history	*prev;
}						t_history;

t_history				*get_head(t_history *history);
char					*add_history(t_info *info, char *cmd);
void					free_history(t_history *hist);
void					set_temporary_hist(t_info *info, int set);

#endif

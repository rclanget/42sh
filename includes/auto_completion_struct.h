/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion_struct.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:49:37 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/14 15:49:39 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_COMPLETION_STRUCT_H
# define AUTO_COMPLETION_STRUCT_H

typedef struct				s_dlist
{
	char					*str;
	char					pos;
	struct s_dlist			*suiv;
}							t_dlist;

typedef struct				s_auto_comp
{
	char					*current_dir;
	char					*line;
	int						flag;
	t_dlist					*list_words;
}							t_auto_comp;

#endif

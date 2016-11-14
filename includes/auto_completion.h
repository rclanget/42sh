/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:49:30 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/14 15:49:32 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_COMPLETION_H
# define AUTO_COMPLETION_H

# include "auto_completion_struct.h"

t_dlist		*ajouter_avant(t_dlist *elem, char *str, int is_dir, char *cu_dir);
t_dlist		*cree_liste(char *str, int is_dir, char *cu_dir);
void		vider_liste(t_dlist *head_ref);

void		print_file(char *key, char *line, t_auto_comp *auto_c,\
char *cu_dir);
char		*get_dirname(char *line);
char		*get_basename(char *line, char *slash);

void		fin_auto_completion(t_auto_comp *auto_completion);
char		*word_display(t_dlist *head);
void		next_word(t_auto_comp *auto_completion);
void		integrate_word(t_info *info, char *line, int first_time);
void		free_dir_basename(char *dir, char *file_name);

#endif

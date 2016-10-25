/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 10:45:36 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/25 15:16:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_H
# define OPERATOR_H

void	save_fd(int save);

int		operator_or(t_info *info, t_tree *cmd);
int		operator_and(t_info *info, t_tree *cmd);
int		operator_pipe(t_info *info, t_tree *cmd);
int		operator_comma(t_info *info, t_tree *cmd);

int		redirection_right(t_info *info, t_tree *cmd);
int		redirection_dright(t_info *info, t_tree *cmd);
int		redirection_left(t_info *info, t_tree *cmd);
int		redirection_dleft(t_info *info, t_tree *cmd);

int		redirection_get_fd(t_tree *cmd, int *fds);
#endif

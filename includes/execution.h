/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 15:30:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/03 12:59:08 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "shell.h"

int		execution_motor(t_info *info, t_tree *cmd, int wait);
int		execution_command(t_info *info, t_tree *cmd, int wait);
int		execution_status(int status);
char	*executable_search(t_info *info, char *exec);

#endif

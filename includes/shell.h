/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:09:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/28 15:03:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "env_struct.h"
# include "hashmap_struct.h"
# include "parser.h"
# include "termcaps_struct.h"
# include "auto_completion.h"

typedef struct			s_info
{
	struct s_tree		*cmd;
	struct s_alias		*alias;
	struct s_env		*env;
	struct s_hashmap	*hash;
	struct s_termcaps	*term;
	struct s_history	*hist;
	struct s_auto_comp	auto_completion;
	int					stop;
	int					status;
	char				*self;
}						t_info;

t_hashmap				*pre_creer_hashmap(char *path, t_hashmap *map);
void					hashmap_free(t_hashmap *map);

void					ft_init_env(t_info *info, char **env);

int						execution_motor(t_info *info, t_tree *cmd, int wait);

void					ft_exit_shell(t_info *info);

#endif

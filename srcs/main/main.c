/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:51:51 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 17:40:00 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "env.h"
#include "operator.h"
#include "command_line_termcaps.h"
#include "alias.h"
#include "syntax.h"
#include "execution.h"
#include "history.h"
#include "tools.h"

t_info				*init_shell(int ac, char **av, char **env)
{
	t_info			*info;
	t_termcaps		*term;

	(void)ac;
	info = NULL;
	term = NULL;
	if ((info = (t_info *)ft_memalloc(sizeof(t_info))) &&
		(term = (t_termcaps *)ft_memalloc(sizeof(t_termcaps))))
	{
		ft_signal(0);
		info->self = realpath(av[0], NULL);
		info->term = term;
		info->term->is_term = termcap_available();
		info->term->capa = termcap_capainit();
		info->term->prompt = ft_strdup("$> ");
		ft_init_env(info, env);
		info->hash = pre_creer_hashmap(ft_strdup((search_env_var(info, "PATH"))
			? search_env_var(info, "PATH")->content : NULL), NULL);
	}
	else
		ft_free_them_all(2, &info, &term);
	return (info);
}

void				exit_shell(t_info *info)
{
	free_history(get_head(info->hist));
	ft_free_env(info->env);
	hashmap_free(info->hash);
	info->env = NULL;
	exit(execution_status(info->status));
}

int					main(int ac, char **av, char **env)
{
	t_info			*info;
	char			*command;
	char			*tmp;

	info = init_shell(ac, av, env);
	while ((command = add_history(info, termcaps_readline(info))))
	{
		save_fd(1);
		command = apply_alias_verified(info, command);
		tmp = ft_strtrim(command);
		info->cmd = parser_cmd(tmp);
		ft_free_them_all(2, &command, &tmp);
		if (syntax_check(info->cmd, 1) && modif_tree(info->cmd))
			execution_motor(info, info->cmd, 1);
		info->cmd = parser_free_cmd(info->cmd);
		save_fd(0);
		info->term->pos_c = 0;
		if (info->stop)
			break ;
		update_path(info, search_env_var(info, "PATH"));
	}
	exit_shell(info);
	return (0);
}

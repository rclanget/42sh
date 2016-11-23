/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:51:51 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 15:58:59 by zipo             ###   ########.fr       */
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
#include "builtin_history.h"
#include "var.h"

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
		ft_init_env(info, env);
		info->term = term;
		info->term->is_term = termcap_available(env);
		info->term->capa = termcap_capainit();
		info->term->prompt = ft_strdup("$> ");
		info->hash = pre_creer_hashmap(ft_strdup((search_env_var(info, "PATH"))
			? search_env_var(info, "PATH")->content : NULL), NULL);
	}
	else
		ft_free_them_all(2, &info, &term);
	return (info);
}

void				exit_shell(t_info *info)
{
	int				status;

	status = info->status;
	free_history(get_head(info->hist));
	ft_free_env(info->env);
	hashmap_free(info->hash);
	free_alias(info->alias);
	free_alias(info->var);
	info->env = NULL;
	ft_free_them_all(6, &info->self, &info->term->capa, &info->term->prompt,
		&info->term->save_cmd, &info->term, &info);
	update_path(NULL, NULL);
	exit(execution_status(status));
}

void				execute_shell(t_info *info, char **command)
{
	save_fd(1);
	*command = parse_var(info, *command);
	*command = apply_alias_verified(info, *command);
	info->cmd = parser_cmd(ft_strtrim(*command));
	if (syntax_check(info->cmd, 1) && modif_tree(info->cmd))
		execution_motor(info, info->cmd, 1);
	info->cmd = parser_free_cmd(info->cmd);
	save_fd(0);
}

int					main(int ac, char **av, char **env)
{
	t_info			*i;
	char			*command;

	i = save_info(init_shell(ac, av, env));
	while ((command = add_history(i, history_excldot(i, termcaps_readline(i)))))
	{
		if (ft_strlen(command))
			execute_shell(i, &command);
		ft_free_them_all(1, &command);
		i->term->pos_c = 0;
		if (i->stop)
			break ;
		update_path(i, search_env_var(i, "PATH"));
	}
	exit_shell(i);
	return (0);
}

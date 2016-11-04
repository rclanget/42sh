/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:51:51 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/31 10:50:37 by ulefebvr         ###   ########.fr       */
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

void        ft_exit_shell(t_info *info) {
	(void)info;
}

int main(int ac, char const **av, char **env) {
	(void)ac;
	(void)av;
	t_info info;
	t_termcaps term;

	ft_bzero(&info, sizeof(info));
	ft_bzero(&term, sizeof(term));

	info.self = realpath(av[0], NULL);

	info.term = &term;
	info.term->is_term = termcap_available();
	info.term->capa = termcap_capainit();
	// info.term->cmd = ft_memalloc(BUFFER_SIZE);
	info.term->prompt = "$> ";

	ft_init_env(&info, env);
	info.alias = NULL;
	info.hash = pre_creer_hashmap(
		ft_strdup(
			(search_env_var(&info, "PATH")) ? search_env_var(&info, "PATH")->content : NULL
		),
		NULL
	);
	ft_signal(0);

	char *command;
	char *tmp;
	while ((command = termcaps_readline(&info)))
	{
		save_fd(1);
		add_history(&info, command);
		command = apply_alias_verified(&info, command);
		tmp = ft_strtrim(command);
		info.cmd = parser_cmd(tmp);
		if (syntax_check(info.cmd, 1))
		{
			modif_tree(info.cmd);
			execution_motor(&info, info.cmd, 1);
		}
		info.cmd = parser_free_cmd(info.cmd);
		save_fd(0);
		ft_free_them_all(2, command, tmp);
		info.term->pos_c = 0;
		// update_path(&info, search_env_var(&info, "PATH"));
	}
	free_history(get_head(info.hist));
	ft_free_env(info.env);
	hashmap_free(info.hash);
	info.env = NULL;
	exit(execution_status(info.status));
}

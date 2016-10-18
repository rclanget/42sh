/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:51:51 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/04 15:12:46 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "env.h"
#include "operator.h"
#include "command_line_termcaps.h"

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

	info.term = &term;
	info.term->is_term = termcap_available();
	info.term->capa = termcap_capainit();
	info.term->cmd = ft_memalloc(BUFFER_SIZE);
	info.term->prompt = "$> ";

	ft_init_env(&info, env);
	info.alias = NULL;

	info.hash = creer_hashmap(ft_strdup((search_env_var(&info, "PATH")) ?
		search_env_var(&info, "PATH")->content : NULL), NULL);

	char *command;
	while ((command = termcaps_readline(&info)))
	{
		ft_print("%s\n", command);
		save_fd(1);
		info.cmd = parser_cmd(command);
		execution_motor(&info, info.cmd, 1);
		info.cmd = parser_free_cmd(info.cmd);
		save_fd(0);
		if (info.term->is_term)
			ft_bzero(info.term->cmd, BUFFER_SIZE);
		else
			free(command);
		info.term->pos_c = 0;
		update_path(&info, search_env_var(&info, "PATH"));
	}

	ft_free_env(info.env);
	hashmap_free(info.hash);
	info.env = NULL;
	return (0);
}

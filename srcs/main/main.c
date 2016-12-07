/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 10:51:51 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/06 11:47:37 by rclanget         ###   ########.fr       */
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

char				*check_dollard_parenthese(char *str)
{
	int				i = 0;
	int				i_mem = 0;

	while (str[i])
	{
		if ((!i || str[i - 1] == ' ') && str[i] == '$' && str[i + 1] && str[i + 1] == '(')
		{
			i_mem = i++;
			while (str[i] && ( str[i] != ')' ||  str[i - 1] == '\\' ))
				i++;
			if (str[i])
			{
				str[i_mem] = '`';
				str[i] = '`';
				i = i_mem;
				while(str[++i_mem])
					str[i_mem] = str[i_mem + 1];
			}
		}
		i++;
	}
	return (str);
}

void				execute_shell(t_info *info, char **command)
{
	save_fd(1);
	*command = check_dollard_parenthese(*command);
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

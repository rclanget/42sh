/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_reverse_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 15:50:49 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/17 13:07:32 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "tools.h"
#include "libft.h"
#include "command_line_termcaps.h"
#include "keyboard_keys.h"

#define KEY_DEL 127
#define SUCCESS "(reverse-i-search)`"
#define FAIL "(failed reverse-i-search)`"

static t_key g_key_tab[] =
{
	{MYKEY_RIGHT, move_cursor_right},
	{MYKEY_LEFT, move_cursor_left},
	{CTRL_A, move_start},
	{KEY_START, move_start},
	{CTRL_E, move_end},
	{KEY_END, move_end},
	{KEY_SUPP, move_supp},
	{CTRL_U, move_clear_left},
	{CTRL_K, move_clear_right},
	{CTRL_L, move_clear_screen},
	{CTRL_UP, move_line_up},
	{CTRL_DOWN, move_line_down},
	{CTRL_RIGHT, move_word_right},
	{CTRL_LEFT, move_word_left},
	{CTRL_I, cut_line},
	{CTRL_O, copy_line},
	{CTRL_P, paste_line},
	{KEY_UP, move_up},
	{KEY_DOWN, move_down}
};

int				search_history(t_info *info, char *str)
{
	int			ret;
	t_history	*hist;

	ret = 0;
	hist = info->hist;
	while (hist)
	{
		if (ft_strstr(hist->cmd, str))
		{
			info->hist = hist;
			info->term->cmd = hist->cmd;
			ret = 1;
			break ;
		}
		hist = hist->next;
	}
	return (ret);
}

static char		*add_chr(char *research, char chr)
{
	char		*tmp_research;

	if (chr != KEY_DEL)
	{
		tmp_research = ft_strdup(research);
		free(research);
		research = ft_strjoinc(tmp_research ? tmp_research : "", chr);
		free(tmp_research);
	}
	else if (research)
		research[(ft_strlen(research)) ? ft_strlen(research) - 1 : 0] = 0;
	return (research);
}

int				handling_key(t_info *info, long chr, char *research)
{
	int			i;
	int			ret;
	t_termcaps	*term;

	i = 0;
	ret = 0;
	term = info->term;
	while (i < 19)
	{
		if (g_key_tab[i].key == chr)
		{
			move_cursor(term->capa, ft_strlen(term->cmd) + 30 +
				ft_strlen(research), 0, 0);
			term->pos_c = ft_strlen(term->cmd);
			ft_print("%s%s%s", term->capa->str_cd, term->prompt, term->cmd);
			g_key_tab[i].f(info);
			ret = 1;
			break ;
		}
		i++;
	}
	return (ret);
}

void			print_research(t_info *info, char *research, int find)
{
	char		*prompt;
	t_termcaps	*t;

	t = info->term;
	prompt = find ? ft_strdup(SUCCESS) : ft_strdup(FAIL);
	move_cursor(t->capa, ft_strlen(t->cmd) + 30 + ft_strlen(research), 0, 0);
	ft_print("%s%s%s': %s", t->capa->str_cd, prompt, research, t->cmd);
	free(prompt);
}

void			reverse_search_i(t_info *info)
{
	int			ret;
	long		chr;
	char		*research;
	int			find;

	chr = 0;
	research = NULL;
	ft_bzero(info->term->cmd, (sizeof(char) * BUFFER_SIZE));
	print_research(info, "", 1);
	while ((ret = read(0, &chr, sizeof(chr))) > 0)
	{
		if ((chr == NL) || handling_key(info, chr, research)
			|| (chr == CTRL_D && (ret = -1) == -1))
				break ;
		research = add_chr(research, (int)chr);
		find = search_history(info, research);
		print_research(info, research, find);
		chr = 0;
	}
	if (research)
		free(research);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history_optcd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:34:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/02 04:49:25 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "builtin_history.h"
#include "libft.h"
#include "tools.h"
#include "shell.h"

static void		print_line(int n, char *s)
{
	int			tmp_n;
	int			nbr_space;

	tmp_n = n;
	nbr_space = 4;
	while (tmp_n >= 10)
	{
		tmp_n /= 10;
		nbr_space--;
	}
	while (nbr_space-- > 0)
		ft_putchar(' ');
	ft_print("%d  %s\n", n, s);
}

static void		delay_other(t_history *hist)
{
	while (hist)
	{
		--(hist->n);
		hist = hist->prev;
	}
}

int				history_base(t_info *info, char **av)
{
	int			limit;
	t_history	*hist;

	limit = 0;
	if ((hist = get_head(info->hist)))
	{
		if (av && *av)
		{
			if (!(limit = ft_atoi(*av)))
				return (0);
		}
		while (hist->next && --limit)
			hist = hist->next;
		while (hist)
		{
			print_line(hist->n, hist->cmd);
			hist = hist->prev;
		}
		return (1);
	}
	return (0);
}

int				history_clear(t_info *info, char **av)
{
	(void)av;
	free_history(get_head(info->hist));
	info->hist = NULL;
	add_history(info, NULL);
	return (1);
}

int				history_deloffset(t_info *info, char **av)
{
	t_history	*hist;
	int			offset;

	if (!av || !*av || !**av || !(hist = get_head(info->hist)))
		return (0);
	offset = ft_atoi(*av);
	while (hist)
	{
		if (hist->n == offset)
		{
			if (hist->prev)
				hist->prev->next = hist->next;
			else
				info->hist = hist->next;
			if (hist->next)
				hist->next->prev = hist->prev;
			delay_other(hist->prev);
			ft_free_them_all(2, &hist->cmd, &hist);
			break ;
		}
		hist = hist->next;
	}
	return (1);
}

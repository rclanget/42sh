/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_historic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:05:25 by rclanget          #+#    #+#             */
/*   Updated: 2015/11/25 16:05:41 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		free_line(t_term *line)
{
	if (line)
	{
		free_line(line->next);
		free(line);
	}
}

void		free_hist_line(t_histc *sline)
{
	if (sline)
	{
		if (sline->line)
			free_line(sline->line);
		free_hist_line(sline->next);
		free(sline);
	}
}

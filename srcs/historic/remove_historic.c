/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_historic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 15:43:34 by ulefebvr          #+#    #+#             */
/*   Updated: 2015/10/21 15:52:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#include <stdio.h>

void		remove_historic(t_info *info)
{
	t_histc		*hist;

	if ((hist = info->historic))
	{
		while (hist->next)
			hist = hist->next;
		if (hist->prev)
			hist->prev->next = NULL;
		free_hist_line(hist);
	}
}

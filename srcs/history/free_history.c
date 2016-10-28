/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:23:19 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/27 15:26:11 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "history.h"

void			free_history(t_history *hist)
{
	if (hist)
	{
		free_history(hist->next);
		ft_free_them_all(2, hist->cmd, hist);
	}
}

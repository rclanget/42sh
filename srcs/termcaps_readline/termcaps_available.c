/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_available.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:02:30 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/26 11:32:14 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

#include <stdlib.h>
#include <termcap.h>

int termcap_available(void)
{
	int		ret;
	char	*term;

	ret = 0;
	if ((term = ft_getenv("TERM")))
	{
		if ((tgetent(NULL, term) > 0))
			++ret;
		free(term);
	}
	return (ret);
}

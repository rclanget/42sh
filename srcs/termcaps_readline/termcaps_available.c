/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_available.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 11:02:30 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 17:27:09 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

#include <stdlib.h>
#include <termcap.h>

int	termcap_available(char **env)
{
	int		ret;
	char	*term;

	ret = 0;
	if ((term = ft_getenv(env, "TERM")))
	{
		if ((tgetent(NULL, term) > 0))
			++ret;
		free(term);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:35:17 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/30 15:47:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

int		termcaps_save(int save_or_restore)
{
	static struct termios	save;
	static char				saved = 0;

	if (save_or_restore)
	{
		if (tcgetattr(0, &save) != -1)
			saved = 1;
	}
	else
	{
		if (saved)
			tcsetattr(0, TCSANOW, &save);
	}
	return (saved ? 1 : 0);
}

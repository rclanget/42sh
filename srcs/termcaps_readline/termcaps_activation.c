/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_activation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 00:58:45 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/01/28 19:33:32 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <unistd.h>

int		termcaps_activation(int is_term)
{
	int				ret;
	struct termios	t;

	ret = 0;
	if (is_term && tcgetattr(0, &t) != -1)
	{
		t.c_lflag = t.c_lflag & ~ICANON;
		t.c_lflag = t.c_lflag & ~ECHO;
		t.c_cc[VMIN] = 1;
		t.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSANOW, &t) != -1)
			ret = 1;
	}
	return (ret);
}

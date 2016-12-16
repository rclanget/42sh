/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap_winsz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 19:36:57 by zipo              #+#    #+#             */
/*   Updated: 2016/12/14 20:42:27 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_line_termcaps.h"

#include <unistd.h>
#include <sys/ioctl.h>

int		termcap_winsz_x(void)
{
	struct winsize w;

	if (-1 != ioctl(STDOUT_FILENO, TIOCGWINSZ, &w))
		return (w.ws_col);
	return (0);
}

int		termcap_winsz_y(void)
{
	struct winsize w;

	if (-1 != ioctl(STDOUT_FILENO, TIOCGWINSZ, &w))
		return (w.ws_row);
	return (0);
}

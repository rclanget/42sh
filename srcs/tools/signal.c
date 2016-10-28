/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 17:37:47 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/28 18:33:13 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

void sig_ign(int signal)
{
	(void)signal;
	exit(0);
}

int	ft_signal(int i)
{
	signal(SIGINT, i ? sig_ign : SIG_IGN);
	signal(SIGINT, i ? sig_ign : SIG_IGN);
	return (0);
}

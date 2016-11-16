/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 16:33:30 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/16 12:53:59 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>

int				execution_status(int status)
{
	return (!(WIFEXITED(status) && !WIFSIGNALED(status)
		&& !WEXITSTATUS(status)));
}

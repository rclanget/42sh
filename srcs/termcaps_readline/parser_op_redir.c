/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_op_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 14:39:41 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/23 18:45:02 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_op_redir(char *str)
{
	int ret;

	ret = 0;
	if ((ret = check_op_dright(str)))
	;
	else if ((ret = check_op_right(str)))
	;
	else if ((ret = check_op_dleft(str)))
	;
	else if ((ret = check_op_left(str)))
	;
	return (ret);
}

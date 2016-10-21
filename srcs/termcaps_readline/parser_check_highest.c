/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_highest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:08:01 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/21 16:31:50 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"

t_parse g_parse2[] =
{
	{1, check_op_comma, parse_op_comma},
	{2, check_op_and, parse_op_and},
	{3, check_op_or, parse_op_or},
	{4, check_op_pipe, parse_op_pipe},
	{5, check_op_right, parse_op_right},
	{6, check_op_left, parse_op_left},
	{7, check_op_dright, parse_op_dright},
	{8, check_op_dleft, parse_op_dleft},
	{0, NULL, NULL}
};

t_parse g_parse[] =
{
	{1, check_op_comma, parse_op_comma},
	{23, check_op_logical, NULL},
	{4, check_op_pipe, parse_op_pipe},
	{5678, check_op_redir, NULL},
	{0, NULL, NULL}
};

int			check_hightest(char *cmd, int i)
{
	int ret;

	return ((ret = g_parse[i].check(cmd)) ? ret : 0);
}

char		**split_on(char *cmd, int pos, int type)
{
	return (g_parse2[type - 1].parse(cmd, pos));
}

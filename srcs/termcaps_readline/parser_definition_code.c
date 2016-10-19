/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_definition_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 19:51:35 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/19 22:06:16 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		is_operator(char cmd)
{
	int ret;

	ret = 0;
	if (cmd == '>')
		ret = C_CHEV_R;
	else if (cmd == '<')
		ret = C_CHEV_L;
	else if (cmd == '(' || cmd == ')')
		ret = C_PARENTHESE;
	else if (cmd == '{' || cmd == '}')
		ret = C_BRACKET;
	else if (cmd == '|')
		ret = C_PIPE;
	else if (cmd == '&')
		ret = C_AMP;
	else if (cmd == ';')
		ret = C_SEMICOL;
	return (ret);
}

void	skip_space(char *cmd, int *i)
{
	while (cmd[*i] && cmd[*i] == ' ')
		*i += 1;
}

int		*definition_code(char *cmd)
{
	static int *codes;

	if (cmd)
	{
		codes = get_operator(cmd);
		codes = get_cmd(cmd, codes);
		codes = get_arg(cmd, codes);
		codes = get_file(cmd, codes);
		codes = get_quote(cmd, codes);
	}
	return (codes);
}

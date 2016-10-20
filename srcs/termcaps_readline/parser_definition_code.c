/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_definition_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 19:51:35 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/20 10:38:47 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "command_line_termcaps.h"

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
	else if (cmd == '\'')
		ret = C_QUOTE;
	else if (cmd == '\"')
		ret = C_DQUOTE;
	return (ret);
}

int 	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

void	skip_space(char *cmd, int *i)
{
	while (cmd[*i] && ft_isspace(cmd[*i]))
		*i += 1;
}

int		*definition_code(char *cmd)
{
	static int codes[BUFFER_SIZE];

	if (cmd)
	{
		get_operator(cmd, codes);
		get_cmd(cmd, codes);
		get_arg(cmd, codes);
		get_file(cmd, codes);
	}
	return (codes);
}

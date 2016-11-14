/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_definition_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 19:51:35 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/14 16:05:40 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "command_line_termcaps.h"

int		is_quote(char cmd)
{
	char *tmp;
	char *operators;

	operators = "\'\"";
	return (tmp = ft_strchr(operators, cmd)) ? (tmp - operators) + 14 : 0;
}

int		is_operator(char cmd)
{
	char *tmp;
	char *operators;

	operators = "><(){}|&;";
	return (tmp = ft_strchr(operators, cmd)) ? (tmp - operators) + 5 : 0;
}

void	skip_space(char *cmd, int *i)
{
	while (cmd[*i] && IS_SPACE(cmd[*i]))
		*i += 1;
}

int		*definition_code(char *cmd)
{
	static int codes[BUFFER_SIZE];

	if (cmd && *cmd)
	{
		get_operator(cmd, codes);
		get_cmd(cmd, codes);
		get_arg(cmd, codes);
		get_file(cmd, codes);
		get_quote(cmd, codes);
	}
	return (codes);
}

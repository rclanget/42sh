/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_definition_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 19:51:35 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/20 18:01:56 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "command_line_termcaps.h"

int		is_quote(char cmd)
{
	char * tmp;
	char * operators = "\'\"";

	return (tmp = ft_strchr(operators, cmd)) ? (tmp - operators)  + 14: 0;
}

int		is_operator(char cmd)
{
	char * tmp;
	char * operators = "><(){}|&;";

	return (tmp = ft_strchr(operators, cmd)) ? (tmp - operators)  + 5: 0;
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
		get_quote(cmd, codes);
	}
	return (codes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_definition_code.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 19:51:35 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/20 11:26:18 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "command_line_termcaps.h"


# define C_SPACE 		 1
# define C_CMD 			 2
# define C_ARG 			 3
# define C_FILE 		 4
# define C_CHEV_R 		 5
# define C_CHEV_L 		 6
# define C_PARENTHESE_O  7
# define C_PARENTHESE_C	 8
# define C_BRACKET_O	 9
# define C_BRACKET_C	 10
# define C_PIPE 		 11
# define C_AMP 			 12
# define C_SEMICOL 		 13
# define C_QUOTE 		 14
# define C_DQUOTE 		 15

int		is_operator(char cmd)
{
	char * tmp;
	char * operators = "><(){}|&;\'\"";

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
	}
	return (codes);
}

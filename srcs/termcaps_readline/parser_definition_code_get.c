/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_definition_code_get.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 21:59:06 by rclanget          #+#    #+#             */
/*   Updated: 2016/10/20 10:38:41 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"

int	*get_operator(char *cmd, int *codes)
{
	int	i;
	int	code;

	i = 0;
	while (cmd[i])
	{
		if ((code = is_operator(cmd[i])))
			codes[i] = code;
		else
			codes[i] = C_SPACE;
		i++;
	}
	return (codes);
}

int	*get_cmd(char *cmd, int *codes)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if ((!i && codes[i] == C_SPACE) || codes[i] > C_CHEV_L)
		{
			if ((!i && codes[i] != C_SPACE) || i)
				i++;
			skip_space(cmd, &i);
			while (cmd[i] && !ft_isspace(cmd[i]) && codes[i] == C_SPACE)
				codes[i++] = C_CMD;
		}
		else
			i++;
	}
	return (codes);
}

int	*get_arg(char *cmd, int *codes)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (codes[i] == C_CMD)
		{
			while (codes[i] && codes[i] == C_CMD)
				i++;
			skip_space(cmd, &i);
			while (cmd[i] && codes[i] == C_SPACE)
			{
				if (cmd[i] != ' ')
					while (cmd[i] && cmd[i] != ' ' && codes[i] == C_SPACE)
						codes[i++] = C_ARG;
				else
					i++;
			}
		}
		else
			i++;
	}
	return (codes);
}

int	*get_file(char *cmd, int *codes)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while (cmd[i])
	{
		if (codes[i] == C_CHEV_R || codes[i] == C_CHEV_L)
		{
			if ((value = (codes[i] == C_CHEV_L && codes[i + 1] \
				&& codes[i + 1] == C_CHEV_L) ? C_ARG : C_FILE) == C_ARG)
				i += 1;
			i++;
			skip_space(cmd, &i);
			while (cmd[i] && cmd[i] != ' ' && codes[i] == C_SPACE)
				codes[i++] = value;
		}
		else
			i++;
	}
	return (codes);
}

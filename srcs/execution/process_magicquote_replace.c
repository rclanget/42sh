/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_magicquote_replace.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:57:38 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/09 14:57:47 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*check_dollard_parenthese(char *cmd)
{
	int				i;
	int				i_mem;

	i = 0;
	i_mem = 0;
	while (cmd[i])
	{
		if ((!i || cmd[i - 1] == ' ') &&\
		cmd[i] == '$' && cmd[i + 1] && cmd[i + 1] == '(')
		{
			i_mem = i++;
			while (cmd[i] && (cmd[i] != ')' || cmd[i - 1] == '\\'))
				i++;
			if (cmd[i])
			{
				cmd[i_mem] = '`';
				cmd[i] = '`';
				i = i_mem;
				while (cmd[++i_mem])
					cmd[i_mem] = cmd[i_mem + 1];
			}
		}
		i++;
	}
	return (cmd);
}

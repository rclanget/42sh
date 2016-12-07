/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_match_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:17 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_match.h"
#include "glob_token.h"

bool	ft_glob_match_char(t_list *it, char c)
{
	char	*p;

	if (0 == GLOB_MATCH_CHAR)
		return (false);
	if (GLOB_QUESTION == C_TOKEN(it)->type)
		return (true);
	p = C_TOKEN(it)->handle->str;
	while (GLOB_EOS != *p)
		if (*p++ == c)
			return (C_TOKEN(it)->is_not == false);
	return (C_TOKEN(it)->is_not == true);
}

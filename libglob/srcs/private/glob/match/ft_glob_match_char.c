/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_match_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:36:53 by igomez            #+#    #+#             */
/*   Updated: 2016/12/06 13:50:14 by ulefebvr         ###   ########.fr       */
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

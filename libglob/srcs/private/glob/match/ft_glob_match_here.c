/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_match_here.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:24:19 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glob_match.h"
#include "glob_token.h"

bool	ft_glob_match_here(t_list *it, t_list *head, char const *s)
{
	bool	ret;

	if (it == head)
		return (GLOB_EOS == *s);
	if (GLOB_STAR == C_TOKEN(it)->type)
	{
		ret = ft_glob_match_here(it->next, head, s);
		if (GLOB_EOS == *s)
			return (ret);
		return (ret || ft_glob_match_here(it, head, s + 1));
	}
	if (false == ft_glob_match_char(it, *s))
		return (false);
	return (ft_glob_match_here(it->next, head, s + 1));
}

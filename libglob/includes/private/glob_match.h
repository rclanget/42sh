/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_match.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2016/12/06 17:44:32 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_MATCH_H
# define GLOB_MATCH_H

/*
** Include t_list
*/
# include "glob_list.h"

/*
** Include bool, true, false
*/
# include <stdbool.h>

/*
** Matching with (1) are correctly implemented
*/
# define GLOB_MATCH_CHAR		(1)
# define GLOB_MATCH_STAR		(1)
# define GLOB_MATCH_PLUS		(1)
# define GLOB_MATCH_QUESTION	(1)

/*
** Match between string and glob_pattern (100% Posix)
**	==> http://man7.org/linux/man-pages/man7/glob.7.html
*/
bool		ft_glob_match(
				char const *string,
				char const *glob_pattern
);

/*
** Match from current token
*/
bool		ft_glob_match_here(
				t_list *it,
				t_list *head,
				char const *string
);

/*
** Match char
*/
bool		ft_glob_match_char(
				t_list *it,
				char c
);

#endif

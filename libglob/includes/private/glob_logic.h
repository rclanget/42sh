/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_logic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:19:23 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:19:24 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_LOGIC_H
# define GLOB_LOGIC_H

/*
** Include t_string
*/
# include "glob_string.h"

/*
** Include t_list
*/
# include "glob_list.h"

/*
** ============================================================================
** Glob split curly
**
** Ex: "aaa{bbb,ccc}ddd"
**	==> pre  : aaa
**	==> in   : bbb,ccc
**	==> post : ddd
**
** Generating 2 pattern distinc:
**	==>	"aaabbbddd"
**	==> "aaacccddd"
*/
typedef struct		s_glob_split
{
	t_string		*pre;
	t_string		*in;
	t_string		*post;
}					t_glob_split;

/*
** ============================================================================
** Logic glob list, containing tokens (used with curly bracket)
*/
typedef struct		s_glob_logic
{
	t_string		*pattern;
	t_list			token_head;
	t_list			list;
}					t_glob_logic;

/*
** Logic accessor from list
*/
# define C_LOGIC(it)	CONTAINEROF(it, t_glob_logic, list)

/*
** Get deepest left-curly (not escaped)
*/
char				*ft_glob_logic_get_first(
						char const *pattern
);

/*
** Get corresponding right-curly (not escaped)
*/
char				*ft_glob_logic_get_second(
						char const *lcurly
);

/*
** Split pattern into glob_split struct.
*/
t_glob_split		*ft_glob_logic_split(
						char const *pattern
);

/*
** Free split
*/
void				ft_glob_logic_split_del(
						t_glob_split **ptr
);

/*
** Create new logic struct contained every tokens
*/
void				ft_glob_new_logic(
						char const *pattern
);

/*
** Delete logic item
*/
void				ft_glob_logic_del(
						t_list *it
);

#endif

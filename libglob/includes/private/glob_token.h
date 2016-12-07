/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2016/12/06 17:44:54 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_TOKEN_H
# define GLOB_TOKEN_H

/*
** Include t_string
*/
# include "glob_string.h"

/*
** Include t_list
*/
# include "glob_list.h"

/*
** Include t_glob_logic
*/
# include "glob_logic.h"

/*
** Token's types
*/
# define GLOB_EOS		(0)
# define GLOB_STAR		('*')
# define GLOB_QUESTION	('?')
# define GLOB_NOT		('!')
# define GLOB_LBRACKET	('[')
# define GLOB_RBRACKET	(']')
# define GLOB_RANGE		('-')
# define GLOB_LCURLY	('{')
# define GLOB_RCURLY	('}')
# define GLOB_SEPARATOR	(',')
# define GLOB_BEGIN		('^')
# define GLOB_END		('$')
# define GLOB_ESCAPE	('\\')
# define GLOB_CHAR		((char)-1)
# define GLOB_LIST		((char)-2)
# define GLOB_ANY		((char)-3)

/*
** Token List
*/
# define GLOB_TOKENS	("*?[-]{,}")

/*
** ============================================================================
** Glob token list
*/
typedef struct			s_glob_token
{
	int					type;
	t_string			*handle;
	bool				is_not;
	t_list				list;
}						t_glob_token;

/*
** Token accessor from list
*/
# define C_TOKEN(it)	CONTAINEROF(it, t_glob_token, list)

/*
** Create new token initialised with a type
**	==> Token is added in global glob list
*/
t_glob_token			*ft_glob_new_token(
							int type
);

/*
** Create new token using simple char
** 	==> Created with GLOB_CHAR by default
*/
bool					ft_glob_new_token_from_char(
							t_glob_logic *logic,
							char c
);

/*
** Append a char in the token
*/
void					ft_glob_token_append(
							t_glob_token *token,
							char c
);

/*
** Delete actual token.
*/
void					ft_glob_token_del(
							t_list *it
);

#endif

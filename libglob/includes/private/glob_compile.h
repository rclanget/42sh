/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_compile.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2016/12/06 17:40:04 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_COMPILE_H
# define GLOB_COMPILE_H

/*
** Include t_glob_token
*/
# include "glob_token.h"

/*
** Include t_glob_finder
*/
# include "glob_finder.h"

/*
** Include t_string
*/
# include "glob_string.h"

/*
** Include bool, true, false
*/
# include <stdbool.h>

/*
** ============================================================================
** Struct table, used for glob-class pattern (Ex: [:digit:])
*/
typedef struct		s_glob_ascii
{
	size_t			size;
	char const		*pattern;
	int				(*func)(int);
}					t_glob_ascii;

/*
** ============================================================================
** Main glob struct
*/
typedef struct		s_glob
{
	t_list			logic_head;
	t_list			finder_head;
}					t_glob;

/*
** Singleton
*/
t_glob				*ft_singleton_glob(void);

/*
** Compile glob pattern into t_glob; false if any error.
*/
bool				ft_glob_compile(
						char const *pattern
);

/*
** Compile from simple string pattern
*/
bool				ft_glob_compile_pattern(
						t_glob_logic *logic
);

/*
** Compile from logic operand (curly)
*/
void				ft_glob_compile_logic(
						char const *pattern
);

/*
** Compile [list] pattern
*/
int					ft_glob_compile_list(
						t_glob_logic *logic,
						char const *pattern,
						bool is_not
);

/*
** Compile [a-z] (range) pattern;
*/
int					ft_glob_compile_range(
						t_glob_token *token,
						char const *pattern
);

/*
** Compile [:digit:] (class) pattern;
*/
int					ft_glob_compile_class(
						t_glob_token *token,
						char const *pattern
);

/*
** Compile from metachar
*/
bool				ft_glob_compile_metachar(
						t_glob_logic *logic,
						char c
);

/*
** Clear glob
*/
void				ft_delete_glob(void);

#endif

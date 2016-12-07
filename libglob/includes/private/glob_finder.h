/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_finder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:18:53 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:18:56 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_FINDER_H
# define GLOB_FINDER_H

/*
** Include t_list
*/
# include "glob_list.h"

/*
** Include t_string
*/
# include "glob_string.h"

/*
** Get Path from pattern
*/
# define GLOB_PATH(s)	(('/' == *(s)) ? "/" : ".")

/*
** Split glob into different path-glob
*/
# define GLOB_HERE(s)	(ft_glob_finder_get_here(s))
# define GLOB_NEXT(s)	(ft_glob_finder_get_next(s))

/*
** ============================================================================
** Finder list of every item we need to save
**
** ./a.out [A-Z]* titi;
**	==> "./a.out Toto titi;"
*/
typedef struct			s_glob_finder
{
	t_string			*handle;
	t_list				list;
}						t_glob_finder;

/*
** Finder accessor from list
*/
# define C_FINDER(it)	CONTAINEROF(it, t_glob_finder, list)

/*
** Glob finder
*/
char					*ft_glob_finder_engine(
							char const *line,
							void (*f)(char const *)
);

/*
** Find in path and grep every item that match pattern.
*/
bool					ft_glob_finder_exec(
							char const *path,
							char const *pattern
);

/*
** Find in path_dir (joined), and find every item matching
*/
bool					ft_glob_finder_exec_dirs(
							char const *joined,
							char const *pattern,
							char const *name
);

/*
** Join 2 path to create directory
** toto titi
** ==> toto/titi
*/
char					*ft_glob_finder_join_dirs(
							char const *dir,
							char const *pattern
);

/*
** Check if name match pattern
*/
bool					ft_glob_finder_try_match(
							char const *name,
							char const *pattern_here
);

/*
** Delete tab
*/
void					ft_glob_finder_tab_del(
							char ***tab_ptr
);

/*
** Get usefull part of glob
*/
char					*ft_glob_finder_get_here(
							char const *pattern
);

/*
** Get next part of glob
*/
char					*ft_glob_finder_get_next(
							char const *pattern
);

/*
** Ignore treating 'pattern' if it's not a glob
*/
bool					ft_glob_finder_ignore(
							char const *pattern
);

/*
** Split line with ' ';
*/
char					**ft_glob_finder_split(
							char const *line
);

/*
** Create new 'match' item in finder
*/
void					ft_glob_new_finder(
							char const *match
);

/*
** Del item in finder
*/
void					ft_glob_finder_del(
							t_list *it
);

/*
** Let us know if "path" is a directory
*/
bool					ft_glob_finder_is_dir(
							char const *path
);

/*
** Build line from every item that matched.
*/
char					*ft_glob_finder_build(void);

#endif

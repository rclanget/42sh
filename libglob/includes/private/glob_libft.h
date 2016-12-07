/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:19:02 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:19:03 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_LIBFT_H
# define GLOB_LIBFT_H

/*
** Include bool, true, false
*/
# include <stdbool.h>

/*
** Include size_t
*/
# include <stdlib.h>

/*
** Check if pointer 'p' is correclty aligned with 'b' padding.
**	(required for handwritten optimisations)
*/
# define ALIGNED(p, b)	(!(((uintptr_t)(void const *)(p)) & ((b) - 1)))

/*
** Check if there is a byte null in the 8-bytes variable x.
**	(required for handwritten optimisations)
*/
# define DETECTNULL(x)	(((x) - 0x0101010101010101) & ~(x) & 0x8080808080808080)

/*
** Detect a specified byte in the 8-bytes variable x
*/
# define DETECTCHAR(x, y)	(DETECTNULL((x) ^ (y)))

/*
** Optimised memset
*/
void		*ft_tiny_memset(
				void *p,
				int c,
				size_t n
);

/*
** Optimised bzero
*/
void		ft_tiny_bzero(
				void *p,
				size_t n
);

/*
** Optimised memcmp
*/
int			ft_tiny_memcmp(
				void const *s1,
				void const *s2,
				size_t n
);

/*
** Optimised strcmp
*/
int			ft_tiny_strcmp(
				const char *s1,
				const char *s2
);

/*
** Optimised memcpy
*/
void		*ft_tiny_memcpy(
				void *dst,
				void const *src,
				size_t n
);

/*
** Optimised strcpy
*/
char		*ft_tiny_strcpy(
				char *s1,
				char const *s2
);

/*
** Optimised memchr
*/
void		*ft_tiny_memchr(
				void const *m,
				int c,
				size_t n
);

/*
** Optimised strchr
*/
char		*ft_tiny_strchr(
				char const *s,
				int c
);

/*
** Optimised strndup
*/
char		*ft_tiny_strndup(
				char const *s,
				size_t n
);

/*
** Optimised strdup
*/
char		*ft_tiny_strdup(
				char const *s
);

/*
** Optimised strncmp
*/
int			ft_tiny_strncmp(
				char const *s1,
				char const *s2,
				size_t n
);

/*
** Optimised strlen
*/
size_t		ft_tiny_strlen(
				char const *s
);

/*
** Split string using func.
*/
char		**ft_tiny_split_func(
				char const *s,
				int (*func)(int)
);

/*
** Macro ctype, used for direct acess instead of some compare
*/
# define M_ALNUM	(0x0001)
# define M_ALPHA	(0x0002)
# define M_BLANK	(0x0004)
# define M_CTRNL	(0x0008)
# define M_DIGIT	(0x0010)
# define M_GRAPH	(0x0020)
# define M_LOWER	(0x0040)
# define M_PUNCT	(0x0080)
# define M_SPACE	(0x0100)
# define M_UPPER	(0x0200)
# define M_XDIGIT	(0x0400)
# define M_ASCII	(0x0800)
# define M_PRINT	(0x1000)

/*
** Resolver ctype function
*/
int			ft_ctype_mask(int c, int mask);

/*
** Ctype functions
*/
int			ft_tiny_isalnum(int c);
int			ft_tiny_isalpha(int c);
int			ft_tiny_isblank(int c);
int			ft_tiny_iscntrl(int c);
int			ft_tiny_isdigit(int c);
int			ft_tiny_isgraph(int c);
int			ft_tiny_islower(int c);
int			ft_tiny_ispunct(int c);
int			ft_tiny_isspace(int c);
int			ft_tiny_isupper(int c);
int			ft_tiny_isascii(int c);
int			ft_tiny_isprint(int c);
int			ft_tiny_isxdigit(int c);

#endif

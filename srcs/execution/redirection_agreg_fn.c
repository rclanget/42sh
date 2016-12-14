/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_agreg_fn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:54:07 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/14 17:56:21 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

#include <errno.h>
#include <fcntl.h>

#define FLAG_TRUNC O_RDWR | O_TRUNC | O_CREAT
#define OPEN_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

/*
** The redirection operator: [n]>&word
**.
** shall duplicate one output file descriptor from another, or shall close one.
** If word evaluates to one or more digits, the file descriptor denoted by n,
** or standard output if n is not specified, shall be made to be a copy of the
** file descriptor denoted by word; if the digits in word do not represent a
** file descriptor already open for output, a redirection error shall result;
** see Consequences of Shell Errors.
** If word evaluates to '-', file descriptor n, or standard output if n
** is not specified, is closed. Attempts to close a file descriptor that is not
** open shall not constitute an error. If word evaluates to something else,
** the behavior is unspecified.
**.
**.
** The redirection operator: [n]<&word
**.
** shall duplicate one input file descriptor from another, or shall close one.
** If word evaluates to one or more digits, the file descriptor denoted by n,
** or standard input if n is not specified, shall be made to be a copy of the
** file descriptor denoted by word; if the digits in word do not represent a
** file descriptor already open for input, a redirection error shall result;
** see Consequences of Shell Errors.
** If word evaluates to '-', file descriptor n, or standard input if n is not
** specified, shall be closed. Attempts to close a file descriptor that is not
** open shall not constitute an error. If word evaluates to something else,
** the behavior is unspecified.
**.
*/

int			get_n(char *str, int right)
{
	int		n;

	if ((n = (ft_isdigit(*str)) ? ft_atoi(str) : -1) == -1)
		n = (right) ? 1 : 0;
	if ((right ? write(n, NULL, 0) : read(n, NULL, 0)) < 0)
	{
		ft_fdprint(2, "42sh: %d: %s\n", n, ft_strerror(errno));
		n = -1;
	}
	return (n);
}

int			get_right_word(char **cmd, int i, int *size, char *op)
{
	char	*tmp;
	int		n;

	n = -1;
	if ((tmp = ft_strstr(cmd[i], op) + 2) && *tmp)
	{
		*size = 1;
		if (*tmp == '-')
			n = -2;
		else if (*tmp && ft_isdigit(*tmp))
		{
			n = ft_atoi(tmp);
			if ((write(n, NULL, 0) < 0) && (n = -1))
				ft_fdprint(2, "42sh: %d: %s\n", n, ft_strerror(errno));
		}
		else
			n = open(tmp, FLAG_TRUNC, OPEN_MODE);
	}
	else if (cmd[i + 1] && (*size = 2))
		n = open(cmd[i + 1], FLAG_TRUNC, OPEN_MODE);
	return (n);
}

int			get_left_word(char **cmd, int i, int *size)
{
	char	*tmp;
	int		n;

	n = -1;
	if ((tmp = ft_strstr(cmd[i], "<&") + 2) && *tmp)
	{
		*size = 1;
		if (*tmp == '-')
			n = -2;
		else if (*tmp && ft_isdigit(*tmp))
		{
			n = ft_atoi(tmp);
			if ((read(n, NULL, 0) < 0) && (n = -1))
				ft_fdprint(2, "42sh: %d: %s\n", n, strerror(errno));
		}
	}
	else if (cmd[i + 1])
	{
		*size = 2;
		n = ft_atoi(cmd[i + 1]);
		if ((read(n, NULL, 0) < 0) && (n = -1))
			ft_fdprint(2, "42sh: %d: %s\n", n, strerror(errno));
	}
	return (n);
}

void		do_redirection(int n, int word, int right, int doubl)
{
	if (doubl)
	{
		if (word == -2)
		{
			close(1);
			close(2);
		}
		else
		{
			dup2(word, 1);
			dup2(word, 2);
		}
	}
	else
	{
		if (word == -2)
			close(n);
		else
			dup2(right ? word : n, right ? n : word);
	}
}

#define IS_REDIR_RIGHT(x) (x == 2 ? 0 : 1)
#define IS_REDIR_ALL(x) (x == 3 ? 1 : 0)
#define WHICH_REDIR_RIGHT(x) (IS_REDIR_ALL(x) ? "&>" : ">&")

int			is_redirection_agreg(char **cmd, int i)
{
	int		n;
	int		word;
	int		size;
	int		type;

	size = 0;
	type = 0;
	if (cmd && cmd[i]
		&& ((++type && ft_strstr(cmd[i], ">&"))
		|| (++type && ft_strstr(cmd[i], "<&"))
		|| (++type && ft_strstr(cmd[i], "&>"))))
	{
		if ((n = get_n(cmd[i], IS_REDIR_RIGHT(type))) != -1
			&& -1 != (word = !IS_REDIR_RIGHT(type) ?
			get_left_word(cmd, i, &size) :
			get_right_word(cmd, i, &size, WHICH_REDIR_RIGHT(type))))
			do_redirection(n, word, IS_REDIR_RIGHT(type), IS_REDIR_ALL(type));
		return (size);
	}
	return (0);
}

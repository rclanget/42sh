/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_agreg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:20:25 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/05 20:05:06 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The redirection operator:
**
** [n]>&word
** shall duplicate one output file descriptor from another, or shall close one.
** If word evaluates to one or more digits, the file descriptor denoted by n,
** or standard output if n is not specified, shall be made to be a copy of the file
** descriptor denoted by word; if the digits in word do not represent a file
** descriptor already open for output, a redirection error shall result;
** see Consequences of Shell Errors. If word evaluates to '-', file descriptor n,
** or standard output if n is not specified, is closed. Attempts to close a file
** descriptor that is not open shall not constitute an error. If word evaluates to
** something else, the behavior is unspecified.
*/

#include "libft.h"
#include "error.h"

#include <errno.h>
#include <fcntl.h>

#define			FLAG_TRUNC O_RDWR | O_TRUNC | O_CREAT
#define			OPEN_MODE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int			get_right_n(char *str)
{
    int n;

    n = (ft_isdigit(*str)) ? ft_atoi(str) : 1;
    if (read(n, NULL, 0) < 0)
    {
    	ft_fdprint(2, "42sh: %d: %s\n", n, ft_strerror(errno));
    	n = -1;
    }
    return (n);
}

int         get_right_word(char **cmd, int i, int *size)
{
	char	*tmp;
	int 	n;

	n = 0;
	*size = 2;
	if ((tmp = ft_strstr(cmd[i], ">&") + 2) && *tmp)
	{
		*size = 1;
		if (*tmp == '-')
			n = -2;
		else if (ft_isdigit(*tmp))
		{
			n = ft_atoi(tmp);
		    if ((write(n, NULL, 0) < 0) && (n = -1))
		    	ft_fdprint(2, "42sh: %d: %s\n", n, ft_strerror(errno));
		}
		else
			n = open(tmp, FLAG_TRUNC, OPEN_MODE);
	}
	else if (cmd[i + 1])
		n = open(cmd[i + 1], FLAG_TRUNC, OPEN_MODE);
	return (n);
}

void		do_right_redirection(int n, int word)
{
	if (word == -2)
		close(n);
	else
		dup2(word, n);
}

int	get_left_n(char *str)
{
    int n;

    n = (ft_isdigit(*str)) ? ft_atoi(str) : 1;
    if (read(n, NULL, 0) < 0)
    {
    	ft_fdprint(2, "42sh: %d: %s", n, strerror(errno));
    	n = -1;
    }
    return (n);
}

int get_left_word(char **cmd, int i, int *size)
{
	char	*tmp;
	int 	n;

	n = 0;
	*size = 2;
	if ((tmp = ft_strstr(cmd[i], "<&") + 2) && *tmp)
	{
		*size = 1;
		if (*tmp == '-')
			n = -2;
		else if (ft_isdigit(*tmp))
		{
			n = ft_atoi(tmp);
		    if ((read(n, NULL, 0) < 0) && (n = -1))
		    	ft_fdprint(2, "42sh: %d: %s\n", n, strerror(errno));
		}
	}
	else
	{
		n = ft_atoi(cmd[i + 1]);
		if ((read(n, NULL, 0) < 0) && (n = -1))
		    	ft_fdprint(2, "42sh: %d: %s\n", n, strerror(errno));
	}
	return (n);
}

void		do_left_redirection(int n, int word)
{
	if (word == -2)
		close(n);
	else
	{
		dup2(n, word);
	}
}

int			is_redirection_agreg(char **cmd, int i)
{
	int n;
	int word;
	int size;

	size = 0;
	if (cmd && cmd[i] && ft_strstr(cmd[i], ">&"))
	{
		if ((n = get_right_n(cmd[i])) != -1
			&& (word = get_right_word(cmd, i, &size)) != -1)
			do_right_redirection(n, word);
		return (size);
	}
	else if (cmd && cmd[i] && ft_strstr(cmd[i], "<&"))
	{
		if ((n = get_left_n(cmd[i])) != -1
			&& (word = get_left_word(cmd, i, &size)) != -1)
			do_left_redirection(n, word);
		return (size);
	}
	return (0);
}

char		**clean_command(char **cmd, int i, int size)
{
	while (cmd && cmd[i + size])
	{
		free(cmd[i]);
		cmd[i] = cmd[i + size];
		++i;
	}
	cmd[i] = 0;
	return (cmd);
}

char		**redirection_agreg(char **cmd)
{
	int		i;
	int		size;

	i = 0;
	while (cmd && cmd[i])
	{
		if ((size = is_redirection_agreg(cmd, i)))
		{
			cmd = clean_command(cmd, i, size);
		}
		++i;
	}
	return cmd;
}

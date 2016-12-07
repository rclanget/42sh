/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glob_finder_is_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:23:11 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdbool.h>

bool		ft_glob_finder_is_dir(char const *path)
{
	struct stat st;

	if (stat(path, &st) != 0)
		return (false);
	return (!!(S_ISDIR(st.st_mode)));
}

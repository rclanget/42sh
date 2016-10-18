#include "shell.h"

#include <stdlib.h>
#include "libft.h"

char *ft_strjoinb(char *s1, char *s2, int n)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	if (s1)
	{
		line = (char *)malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
		tmp = line;
		while (*s1 && (*line++ = *s1++))
			;
		while (n--)
			*line++ = *s2++;
		*line = 0;
	}
	else
		return (ft_strndup(s2, 1));
	return (tmp);
}
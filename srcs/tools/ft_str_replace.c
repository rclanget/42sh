#include "libft.h"
#include "tools.h"

char	*ft_str_replace(const char *string, const char *substr, const char *replacement, int i)
{
	char *tok = NULL;
	char *newstr = NULL;
	char *oldstr = NULL;

	if ( substr == NULL || replacement == NULL )
		return (ft_strdup (string));
	newstr = strdup (string);
	tok = &newstr[i];
	oldstr = newstr;
	newstr = (char *)malloc(ft_strlen(oldstr) - ft_strlen(substr) + ft_strlen(replacement) + 1);
	if (newstr == NULL)
	{
		free (oldstr);
		return (NULL);
	}
	ft_memcpy(newstr, oldstr, tok - oldstr);
	ft_memcpy(newstr + (tok - oldstr), replacement, ft_strlen(replacement));
	ft_memcpy(newstr + (tok - oldstr) + ft_strlen(replacement), tok + ft_strlen(substr), ft_strlen(oldstr) - ft_strlen(substr) - (tok - oldstr));
	ft_memset(newstr + ft_strlen(oldstr) - ft_strlen(substr) + ft_strlen(replacement) , 0, 1);
	free(oldstr);
	return (newstr);
}

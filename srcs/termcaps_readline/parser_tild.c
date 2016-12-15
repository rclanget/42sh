#include "libft.h"
#include "execution.h"
#include "tools.h"
#include "env.h"

int				find_tild(char *cmd)
{
	int		i;
	char	quote;
	char	d_quote;

	init_assignation_localvar(&i, &quote, &d_quote);
	while (cmd && cmd[i])
	{
		if (cmd[i] == '"')
			change_state(&d_quote);
		else if (cmd[i] == '\'')
			change_state(&quote);
		if (quote == '0' && d_quote == '0' && cmd[i] == '~' && (!i || cmd[ i - 1] != '~'))
		{
			if ((i && cmd[i - 1] == '\\') || (cmd[i + 1] && !ft_strchr("/+- )`", cmd[i + 1])))
				;
			else
				return (i);
		}
		i++;
	}
	return (0);
}

char			*replace_tild(t_info *info, char *command, int pos)
{
	char	*t1;
	char	*t2;
	char	*t3;
	char	*tmp;
	char	*home;
	char	*pwd;
	char	*oldpwd;
	t_env	*ret_search_env;

	tmp = NULL;
	t1 = (char *)malloc(sizeof(char) * 2);
	t2 = (char *)malloc(sizeof(char) * 3);
	t3 = (char *)malloc(sizeof(char) * 3);
	t1[1] = 0;
	t2[2] = 0;
	t3[2] = 0;
	t1[0] = '~';
	t2[0] = '~';
	t2[1] = '+';
	t3[0] = '~';
	t3[1] = '-';
	ret_search_env = search_env_var(info, "HOME");
	if (ret_search_env)
		home = ret_search_env->content;
	ret_search_env = search_env_var(info, "PWD");
	if (ret_search_env)
		pwd = ret_search_env->content;
	ret_search_env = search_env_var(info, "OLDPWD");
	if (ret_search_env)
		oldpwd = ret_search_env->content;
	if ((command[pos + 0] && command[pos + 0] == '~' && command[pos + 1] == '\0') ||\
		(command[pos + 0] && command[pos + 0] == '~' && command[pos + 1] != '+' && command[pos + 1] != '-'))
	{	
		tmp = ft_str_replace(command, t1, home, pos);
	}
	else if (command[pos + 1] && command[pos + 1] == '+')
		tmp = ft_str_replace(command, t2, pwd, pos);
	else if (command[pos + 1] && command[pos + 1] == '-')
		tmp = ft_str_replace(command, t3, oldpwd, pos);
	free(t1);
	free(t2);
	free(t3);
	return (tmp);
}
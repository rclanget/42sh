#include "history.h"
#include "tools.h"
#include "libft.h"
#include "command_line_termcaps.h"

# define KEY_DEL			127

int			search_history(t_info *info, char *str)
{
	int			ret;
	t_history 	*hist;

	ret = 0;
	hist = info->hist;
	while (hist)
	{
		if (ft_strstr(hist->cmd, str))
		{
			info->hist = hist;
			info->term->cmd = hist->cmd;
			ret = 1;
			break;
		}
		hist = hist->next;
	}
	return (ret);
}

static char		*add_chr(char *research, char chr)
{
	char *tmp_research;

	tmp_research = NULL;
	if (chr != KEY_DEL)
	{
		tmp_research = ft_strjoin_custom(research, &chr);
		free(research);
		research = tmp_research;
	}
	else
		research[ft_strlen(research) - 1] = 0;
	return (research);
}

int            handling_key(t_info *info, char *buffer, long chr)
{
    int ret;

    ret = 0;
    if (chr == KEY_DEL && ++ret)
        move_delete(info);
    else if (ft_isprint(chr) && ++ret)
        buffer[ft_strlen(buffer)] = chr;
    return (ret);
}

void        get_search_work(t_info *info)
{
    long    chr;
    char    *buffer;

    buffer = (char **)ft_memalloc(sizeof(char) * BUFFER_SIZE);
    while ((ret = read(0, &chr, sizeof(chr))) > 0)
    {
        if ((chr == NL) || (chr == CTRL_D && (ret = -1) == -1)
            || !handling_key(info, buffer, chr))
            break;
        ROGER_FUNCTION
        FUNCTIOM QUI AFFICHE QUI PRINT DU FEU
        chr = 0;
    }
}

void		reverse_search_i(t_info *info)
{
	// int ret;
	// long chr;
	// char *research;

	// chr = 0;
	// research = NULL;
	// ft_bzero(&info->term->cmd, sizeof(char *) * ft_strlen(info->term->cmd));
	// while ((ret = read(0, &chr, sizeof(chr))) > 0)
 //    {
 //        if ((chr == NL) || (chr == CTRL_D && (ret = -1) == -1))
 //            break;
 //        research = add_chr(research, (char)chr);
 //        search_history(info, research);
	// 	move_cursor(info->term->capa, ft_strlen(info->term->cmd), 0, 0);
	// 	ft_print("%s(reverse-i-search)`%s': %s", info->term->capa->str_cd, research, info->term->cmd);
 //        chr = 0;
 //    }
}

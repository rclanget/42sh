#include "command_line_termcaps.h"
#include "keyboard_keys.h"
#include "libft.h"

#define MIN(a,b) (a < b ? a : b)
#define MAX(a,b) (a > b ? a : b)

void		cut_line(t_info *info)
{
	char	*selection;
	int		start;
	int		plen;
	int		slen;

	start = info->term->pos_c;
	if ((selection = get_selection(info)))
	{
		plen = ft_strlen(info->term->prompt);
		slen = ft_strlen(selection);
		info->term->save_cmd = selection;
		ft_memcpy(&info->term->cmd[MIN(start, info->term->pos_c)],
			&info->term->cmd[MAX(start, info->term->pos_c)],
			ft_strlen(&info->term->cmd[MAX(start, info->term->pos_c)]));
		ft_bzero(&info->term->cmd[ft_strlen(info->term->cmd) - slen],
			sizeof(char) * slen);
		move_cursor(info->term->capa, info->term->pos_c, plen, 0);
		ft_print("%s%s", info->term->capa->str_cd, info->term->cmd);
		move_cursor(info->term->capa, ft_strlen(info->term->cmd), plen,
			(info->term->pos_c = MIN(start, info->term->pos_c)));
	}
}

void		copy_line(t_info *info)
{
    char	*selection;

    if ((selection = get_selection(info)))
    {
        if (info->term->save_cmd)
            free(info->term->save_cmd);
        info->term->save_cmd = ft_strdup(selection);
    }
}

void		paste_line(t_info *info)
{
    int		len;
    int		slen;
    int		pos_c;
    int		plen;

    pos_c = info->term->pos_c;
    if (info->term->save_cmd)
    {
        len = ft_strlen(info->term->cmd);
        plen = ft_strlen(info->term->prompt);
        slen = ft_strlen(info->term->save_cmd);
        if ((len + slen) < BUFFER_SIZE)
        {
            ft_memcpy(&info->term->cmd[pos_c + slen], &info->term->cmd[pos_c], len - pos_c);
            ft_memcpy(&info->term->cmd[pos_c], info->term->save_cmd, slen);
            move_cursor(info->term->capa, pos_c , plen, 0);
            ft_putstr(info->term->cmd);
            move_cursor(info->term->capa, ft_strlen(info->term->cmd) , plen, pos_c + slen);
            info->term->pos_c = pos_c + slen;
        }
    }
}

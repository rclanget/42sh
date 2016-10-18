#include <moulitest.h>

#include "shell.h"
#include <curses.h>
#include <term.h>
#include "libft.h"
#include <memory.h>
#include <unistd.h>
#include <stdio.h>

static void		free_list(t_info *info)
{
	t_term *tmp;

	while (info->term)
	{
		tmp = info->term;
		info->term = info->term->next;
		free(tmp);
	}
	free(info);
}

static void	test_set_cursor_last_simple(t_test *test)
{
	char	*tab_c = "abcdefghijklmnopqrstuvwxyz";
	t_info	*info;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	info->term->cursor = 1;
	info->term = set_cursor_last(info->term);
	mt_assert((info->term->cursor ? 0 : 1));
	while (info->term->next)
		info->term = info->term->next;
	mt_assert((info->term->cursor ? 1 : 0));
	free_list(info);
}

static void	test_set_cursor_last_null(t_test *test)
{
	char	*tab_c = "";
	t_info	*info;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	info->term = set_cursor_last(info->term);
	mt_assert((info->term ? 0 : 1));
	free_list(info);
}

void		suite_test012_get_pos_curser(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_set_cursor_last_simple);
	SUITE_ADD_TEST(suite, test_set_cursor_last_null);
}
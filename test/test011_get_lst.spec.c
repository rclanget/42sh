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

static void	test_lstLen_simple(t_test *test)
{
	char	*tab_c = "abcdefghijklmnopqrstuvwxyz";
	t_info	*info;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	mt_assert((lstLen(info->term) == 25 ? 1 : 0));
	free_list(info);
}

static void	test_lstLen_null(t_test *test)
{
	char	*tab_c = "";
	t_info	*info;
	int i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	mt_assert((lstLen(info->term) == 0 ? 1 : 0));
	free_list(info);
}

static void	test_lstLast_simple(t_test *test)
{
	char	*tab_c = "abcdefghijklmnopqrstuvwxyz";
	t_info	*info;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	mt_assert((lstLast(info->term)->c == 'z' ? 1 : 0));
	free_list(info);	
}

static void	test_lstLast_null(t_test *test)
{
	char	*tab_c = "";
	t_info	*info;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	mt_assert((!lstLast(info->term) ? 1 : 0));
	free_list(info);	
}

void    suite_test011_get_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_lstLen_simple);
	SUITE_ADD_TEST(suite, test_lstLen_null);
	SUITE_ADD_TEST(suite, test_lstLast_simple);
	SUITE_ADD_TEST(suite, test_lstLast_null);
}
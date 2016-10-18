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

static void	test_key_historic(t_test *test)
{
	char	*hist1 = "test1";
	char	*hist2 = "test2";
	char	*hist3 = "test3";
	t_info	*info;
	t_term	*term = NULL;
	int 	result = 1;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (hist3[i])
		info->term = lstAdd(info->term, hist1[i++]);
	add_historic(info, info->term);
	info->term = NULL;
	i = 0;
	while (hist3[i])
		info->term = lstAdd(info->term, hist2[i++]);
	add_historic(info, info->term);
	i = 0;
	info->term = NULL;
	while (hist3[i])
		info->term = lstAdd(info->term, hist3[i++]);
	add_historic(info, info->term);
	term = key_historic(info, 4283163, 0);
	i = 0;
	while (term && (i < 5))
	{
		if (term->c != hist3[i++])
			result = 0;
		term = term->next;
	}
	mt_assert((result && i == 5) ? 1 : 0);

	info->term = key_historic(info, 4283163, 0);
	info->term = key_historic(info, 4283163, 1);
	info->term = key_historic(info, 4283163, 1);
	term = key_historic(info, 4348699, 1);
	i = 0;
	while (term && (i < 5))
	{
		if (term->c != hist2[i++])
			result = 0;
		term = term->next;
	}
	mt_assert((result && i == 5) ? 1 : 0);
	free_list(info);
}

static void	test_key_historic_null(t_test *test)
{
	t_info	*info;
	t_term	*term = NULL;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	term = key_historic(info, 4283163, 0);
	mt_assert(1);
	free_list(info);
}

void suite_test013_key_historic(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_key_historic);
	SUITE_ADD_TEST(suite, test_key_historic_null);
}
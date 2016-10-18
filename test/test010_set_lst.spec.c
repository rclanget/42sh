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

t_info	*create_list(void)
{
	t_info	*info;
	int		i;
	char 	str[] = " mamie mange de la compote";

	i = 0;
	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (str[i] != '\0')
		info->term = lstAdd(info->term, str[i++]);
	return (info);
}

static void		test_lstAdd(t_test *test)
{
	t_info	*info;
	int		i;
	int		result;
	char 	str[] = " mamie mange de la compote";

	test->debug = 1;
	i = 0;
	result = 0;

	int		j;

	j = 0;
	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (str[j] != '\0')
		info->term = lstAdd(info->term, str[j++]);


	while (info->term)
	{
		if (info->term->c != str[i++])
			result = 1;
		info->term = info->term->next;
	}
	mt_assert((result == 0 ? 1 : 0));
	free_list(info);
}

void		test_lstPrint(t_test *test)
{
	t_info	*info;
	char	buffer[256 + 1];
	int		fd[2];
	int		save;

	test->debug = 1;
	save = 0;
	info = create_list();
	pipe(fd);
	save = dup(1);
	dup2(fd[1], 1);
	close(fd[1]);
	lstPrint(info->term);
	read(fd[0], buffer, 256);
	dup2(save, 1);
	mt_assert((!ft_strcmp(buffer, "mamie mange de la compote")));
	free_list(info);
}

static void		test_lstDel(t_test *test)
{
	t_info	*info;
	int		i;
	int		result;
	char 	str[] = " mamie mange de la compote";

	test->debug = 1;
	i = 0;
	result = 0;


	int		j;

	j = 0;
	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (str[j] != '\0')
		info->term = lstAdd(info->term, str[j++]);


	while (info->term)
	{
		if (info->term->c != str[i++])
			result = 1;
		info->term = info->term->next;
	}
	mt_assert((result == 0 ? 1 : 0));
	free_list(info);
}

static void	test_lstMove(t_test *test)
{
	char	tab_c[] = "abcdefghijklmnopqrstuvwxyz";
	t_info	*info;
	t_term	*begin;
	int		i = 0;

	info = (t_info *)malloc(sizeof(t_info));
	info->term = NULL;
	info = ft_init(info);
	while (tab_c[i])
		info->term = lstAdd(info->term, tab_c[i++]);
	// Test default cursor
	begin = info->term;
	while (begin && !begin->cursor)
		begin = begin->next;
	mt_assert((begin->c == 'z' ? 1 : 0));

	// Test left simple
	begin = info->term;
	begin = lstMove(begin, 'l');
	while (begin && !begin->cursor)
		begin = begin->next;
	mt_assert((begin->c == 'y' ? 1 : 0));
	begin = lstMove(begin, 'r');

	// Test left right
	begin = info->term;
	begin = lstMove(begin, 'l');
	begin = lstMove(begin, 'r');
	while (begin && !begin->cursor)
		begin = begin->next;
	mt_assert((begin->c == 'z' ? 1 : 0));

	// Test right simple
	begin = info->term;
	begin = lstMove(begin, 'r');
	while (begin && !begin->cursor)
		begin = begin->next;

	free_list(info);
}

void    suite_test010_set_lst(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_lstAdd);
	SUITE_ADD_TEST(suite, test_lstPrint);
	SUITE_ADD_TEST(suite, test_lstDel);
	SUITE_ADD_TEST(suite, test_lstMove);
}
#include <moulitest.h>
#include "shell.h"

static void test_simple_test(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	mt_assert(strcmp(search_env_var(&info, "TEST1")->content, "content1") == 0);
	ft_free_env(info.env);
}

static void test_unknow_var(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	mt_assert(!search_env_var(&info, "TEST"));
	ft_free_env(info.env);
}

static void test_unknow_env(t_test *test)
{
	t_info info;

	test->debug = 1;
	info.env = NULL;
	mt_assert(!search_env_var(&info, "TEST"));
}

static void test_with_slash(t_test *test)
{
	char *tab[] = {"HOME=/nfs/zfs-student-4/users/2014/ulefebvr/", "TEST2=content2", NULL};
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	mt_assert(!strcmp(search_env_var(&info, "HOME")->content, "/nfs/zfs-student-4/users/2014/ulefebvr/"));
	ft_free_env(info.env);
}

void    suite_test001_search_env_var(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_test);
	SUITE_ADD_TEST(suite, test_unknow_var);
	SUITE_ADD_TEST(suite, test_unknow_env);
	SUITE_ADD_TEST(suite, test_with_slash);
}

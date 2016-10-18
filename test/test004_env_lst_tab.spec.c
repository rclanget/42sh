#include <moulitest.h>
#include "shell.h"
#include "libft.h"

static void test_simple_test(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;
	char **ret;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	ret = env_lst_tab(info.env);
	mt_assert(ret && !strcmp(ret[0], "TEST1=content1") &&
		!strcmp(ret[1], "TEST2=content2") &&
		!strcmp(ret[2], "yolo=swag") &&
		!ret[3]);
	ft_free_env(info.env);
}

static void test_simple_test_removing(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;
	char **ret;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	env_remove_var(&info, "yolo");
	ret = env_lst_tab(info.env);
	mt_assert(ret && !strcmp(ret[0], "TEST1=content1") &&
		!strcmp(ret[1], "TEST2=content2") &&
		!ret[2]);
	ft_free_env(info.env);
}

static void test_simple_null(t_test *test)
{
	char **tab = NULL;
	t_info info;
	char **ret;

	test->debug = 1;
	ft_init_env(&info, tab);
	ret = env_lst_tab(info.env);
	mt_assert(!ret);
	ft_free_env(info.env);
}

// static void test_unexistant_var(t_test *test)
// {
// 	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
// 	t_info info;

// 	test->debug = 1;
// 	ft_init_env(&info, tab);
// 	env_add_var(&info, strdup("yolo"), strdup("swag"));
// 	env_remove_var(&info, "JHG");
// 	ft_free_env(info.env);
// }

void    suite_test004_env_lst_tab(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_test);
	SUITE_ADD_TEST(suite, test_simple_test_removing);
	SUITE_ADD_TEST(suite, test_simple_null);
	// SUITE_ADD_TEST(suite, test_unexistant_var);
}

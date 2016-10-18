#include <moulitest.h>
#include "shell.h"
#include "libft.h"

static void test_simple_test(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	env_remove_var(&info, "yolo");
	mt_assert(!search_env_var(&info, "yolo") &&
		info.env && !info.env->next->next);
	ft_free_env(info.env);
}

static void test_last_var(t_test *test)
{
	char **tab = NULL;
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	env_remove_var(&info, "yolo");
	mt_assert(!info.env);
	ft_free_env(info.env);
}

static void test_env_null(t_test *test)
{
	char **tab = NULL;
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_remove_var(&info, "yolo");
	mt_assert(!info.env);
	ft_free_env(info.env);
}

static void test_unexistant_var(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	env_remove_var(&info, "JHG");
	ft_free_env(info.env);
}

static void test_simple_test_null(t_test *test)
{
	char *tab[] = {"TEST1=content1", "TEST2=content2", NULL};
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	env_remove_var(&info, NULL);
	mt_assert(!info.env->next->next->next);
	ft_free_env(info.env);
}

void    suite_test003_remove_env_var(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_test);
	SUITE_ADD_TEST(suite, test_last_var);
	SUITE_ADD_TEST(suite, test_env_null);
	SUITE_ADD_TEST(suite, test_unexistant_var);
	SUITE_ADD_TEST(suite, test_simple_test_null);
}

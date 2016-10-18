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
	mt_assert(strcmp(search_env_var(&info, "yolo")->content, "swag") == 0 &&
		!info.env->next->next->next);
	ft_free_env(info.env);
}

static void test_env_null(t_test *test)
{
	char **tab = NULL;
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	mt_assert(strcmp(search_env_var(&info, "yolo")->content, "swag") == 0);
	ft_free_env(info.env);
}

static void test_env_multiple_add(t_test *test)
{
	char **tab = NULL;
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup("swag"));
	env_add_var(&info, strdup("yolo1"), strdup("swag1"));
	env_add_var(&info, strdup("yolo2"), strdup("swag2"));
	mt_assert(!strcmp(search_env_var(&info, "yolo")->content, "swag") &&
		!strcmp(search_env_var(&info, "yolo1")->content, "swag1") &&
		!strcmp(search_env_var(&info, "yolo2")->content, "swag2"));
	ft_free_env(info.env);
}

static void test_env_empty_content(t_test *test)
{
	char **tab = NULL;
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("yolo"), strdup(""));
	mt_assert(!strcmp(search_env_var(&info, "yolo")->content, ""));
	ft_free_env(info.env);
}

static void test_env_home(t_test *test)
{
	char **tab = NULL;
	t_info info;

	test->debug = 1;
	ft_init_env(&info, tab);
	env_add_var(&info, strdup("HOME"), strdup("/nfs/zfs-student-4/users/2014/ulefebvr/"));
	mt_assert(!strcmp(search_env_var(&info, "HOME")->content, "/nfs/zfs-student-4/users/2014/ulefebvr/"));
	ft_free_env(info.env);
}


void    suite_test002_add_env_var(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple_test);
	SUITE_ADD_TEST(suite, test_env_null);
	SUITE_ADD_TEST(suite, test_env_multiple_add);
	SUITE_ADD_TEST(suite, test_env_empty_content);
	SUITE_ADD_TEST(suite, test_env_home);
}

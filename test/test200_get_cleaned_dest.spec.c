#include <moulitest.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

#include <unistd.h>

extern char **environ;

char		*get_cleaned_dest(t_info *info, char *destination);
char		*get_new_from_old(t_info *info, char **cmd);

static void test_env_home(t_test *test)
{
	t_info info;
	char *tmp = NULL;

	test->debug = 1;
	ft_init_env(&info, environ);
	tmp = get_cleaned_dest(&info, "~");
	mt_assert(!strcmp(tmp, "/nfs/zfs-student-4/users/2014/ulefebvr"));
	ft_free_env(info.env);
	free(tmp);
}

static void test_env_home_plus_path(t_test *test)
{
	t_info info;
	char *tmp = NULL;

	test->debug = 1;
	ft_init_env(&info, environ);
	tmp = get_cleaned_dest(&info, "~/work");
	mt_assert(!strcmp(tmp, "/nfs/zfs-student-4/users/2014/ulefebvr/work"));
	ft_free_env(info.env);
	free(tmp);
}

static void test_env_oldpath(t_test *test)
{
	t_info info;
	char *tmp = NULL;

	test->debug = 1;
	ft_init_env(&info, environ);
	env_add_var(&info, strdup("OLDPWD"), strdup("/nfs/zfs-student-4/users/2014/ulefebvr/42sh"));
	tmp = get_cleaned_dest(&info, "-");
	mt_assert(!strcmp(tmp, "/nfs/zfs-student-4/users/2014/ulefebvr/42sh"));
	ft_free_env(info.env);
	free(tmp);
}

static void test_cd_oldnew_simple(t_test *test)
{
	t_info info;
	char *tmp = NULL;
	char *tab[] =  {"cd", "ulefebvr", "rclanget"};

	test->debug = 1;
	ft_init_env(&info, environ);
	env_update_var(&info, strdup("PWD"), strdup("/nfs/zfs-student-4/users/2014/ulefebvr/42sh"));
	tmp = get_new_from_old(&info, tab);
	mt_assert(!strcmp(tmp, "/nfs/zfs-student-4/users/2014/rclanget/42sh"));
	ft_free_env(info.env);
	free(tmp);
}

static void test_cd_oldnew_other(t_test *test)
{
	t_info info;
	char *tmp = NULL;
	char *tab[] =  {"cd", "4/u", "2/1"};

	test->debug = 1;
	ft_init_env(&info, environ);
	env_update_var(&info, strdup("PWD"), strdup("/nfs/zfs-student-4/users/2014/ulefebvr/42sh"));
	tmp = get_new_from_old(&info, tab);
	// printf("%s\n", tmp);
	mt_assert(!strcmp(tmp, "/nfs/zfs-student-2/1sers/2014/ulefebvr/42sh"));
	ft_free_env(info.env);
	free(tmp);
}

void    suite_test200_get_cleaned_dest(t_suite *suite)
{
    SUITE_ADD_TEST(suite, test_env_home);
    SUITE_ADD_TEST(suite, test_env_home_plus_path);
    SUITE_ADD_TEST(suite, test_env_oldpath);
    SUITE_ADD_TEST(suite, test_cd_oldnew_simple);
    SUITE_ADD_TEST(suite, test_cd_oldnew_other);
}
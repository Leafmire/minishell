/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 23:05:58 by gson              #+#    #+#             */
/*   Updated: 2022/06/18 18:53:48 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"

static char	*check_oldpath(t_dlist *envlist)
{
	t_env	*cur_env;
	char	*oldpath;

	envlist->cur = envlist->head;
	oldpath = NULL;
	while (envlist->cur != 0)
	{
		cur_env = (t_env *)envlist->cur->content;
		if (ft_strcmp(cur_env->key, "OLDPWD") == 0)
		{
			if (cur_env->value == NULL)
				oldpath = NULL;
			else
				oldpath = cur_env->value;
		}
		envlist->cur = envlist->cur->next;
	}
	return (oldpath);
}

static char	*set_home(t_dlist *envlist)
{
	t_env	*cur_env;
	char	*home;

	envlist->cur = envlist->head;
	while (envlist->cur != 0)
	{
		cur_env = (t_env *)envlist->cur->content;
		if (ft_strcmp(cur_env->key, "HOME") == 0)
		{
			if (cur_env->value == NULL)
				home = NULL;
			else
				home = cur_env->value;
		}
		envlist->cur = envlist->cur->next;
	}
	return (home);
}

int	cd(t_dlist *envlist, int argc, char **argv)
{
	char	*oldpath;
	char	*path;

	if (argc > 1)
		path = argv[1];
	else
		path = set_home(envlist);
	if (ft_strcmp(path, "-") == 0)
	{
		oldpath = check_oldpath(envlist);
		if (oldpath == NULL)
			return (move_directory_old(envlist, path));
		else
			return (move_directory_old(envlist, oldpath));
	}
	else if (ft_strcmp(path, "~") == 0)
		path = set_home(envlist);
	return (move_directory(envlist, path));
}

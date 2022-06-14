/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_helper_func.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:30:30 by hseong            #+#    #+#             */
/*   Updated: 2022/06/15 05:08:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "execute.h"

void	*get_word_from_token(void *content)
{
	t_token	*token;

	token = content;
	return (token->word);
}

void	*env_to_str(void *content)
{
	char	*env_str;
	t_env	*env;
	size_t	env_str_len;

	env = content;
	env_str_len = ft_strlen(env->key) + 1;
	if (env->value != NULL)
		env_str_len += ft_strlen(env->value) + 1;
	env_str = ft_calloc(1, env_str_len);
	ft_strlcat(env_str, env->key, env_str_len);
	if (env->value == NULL)
		return (env_str);
	ft_strlcat(env_str, "=", env_str_len);
	ft_strlcat(env_str, env->value, env_str_len);
	return (env_str);
}

// 5 = sizeof "PATH\0"
char	*get_value_from_env(t_dlist *env_list, const char *key)
{
	t_node	*node;
	t_env	*env;

	node = dlist_find_content(env_list, key, 5, get_key_from_env);
	if (node == NULL)
		return (NULL);
	env = node->content;
	return (env->value);
}

void	*get_key_from_env(void *content)
{
	t_env	*env;

	env = content;
	return (env->key);
}

void	free_path_arr(char **path_arr)
{
	size_t	idx;

	if (path_arr == NULL)
		return ;
	idx = 0;
	while (path_arr[idx])
	{
		free(path_arr[idx]);
		++idx;
	}
	free(path_arr);
}

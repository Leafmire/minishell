/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:31:07 by hseong            #+#    #+#             */
/*   Updated: 2022/06/14 19:36:17 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "readline/readline.h"

char	*minishell_initialize(int argc, char **argv)
{
	char	*prompt;

	(void)argc;
	(void)argv;
	rl_catch_signals = 0;
	prompt = "$> ";
	return (prompt);
}

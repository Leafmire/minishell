/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition_procedure_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:28:28 by hseong            #+#    #+#             */
/*   Updated: 2022/06/18 15:21:11 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "constants.h"
#include "parser/token_recognition.h"

#define OPERATOR_LIST ("<>|&")

int	check_new_operator(t_iterator *iterator, t_token *token, char target)
{
	(void)iterator;
	if (!ft_strchr(OPERATOR_LIST, target))
		return (CONTINUE);
	if (check_token_type(token->type, TT_QUOTE_MASK))
		return (APPLIED);
	if (!check_token_type(token->type, TT_EMPTY))
		return (DELIMIT);
	token->type = get_operator_type(target);
	return (APPLIED);
}

int	check_blank(t_iterator *iterator, t_token *token, char target)
{
	(void)iterator;
	if (!is_ifs(target))
		return (CONTINUE);
	if (check_token_type(token->type, TT_QUOTE_MASK))
		return (APPLIED);
	return (DELIMIT);
}

int	check_word(t_iterator *iterator, t_token *token, char target)
{
	(void)iterator;
	(void)target;
	if (check_token_type(token->type, TT_WORD))
		return (APPLIED);
	return (CONTINUE);
}

int	check_new_word(t_iterator *iterator, t_token *token, char target)
{
	char	next_target;

	next_target = get_char(iterator->line->cur->next);
	if ((target == '~' || target == '*')
		&& (is_ifs(next_target) || next_target == '\0' || next_target == '/'))
	{
		special_expansion(iterator, target, token->type);
		return (APPLIED);
	}
	token->type |= TT_WORD;
	return (APPLIED);
}

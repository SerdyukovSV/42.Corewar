/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:08:23 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:08:24 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		parse_header_arg(int input, t_token *token, int i)
{
	*token = lexer(input);
	while (token->type == (t_types){Whitespace}
	|| token->type == (t_types){Newline})
		*token = lexer(input);
	if (token->type != (t_types){Symbol} || *(token->str) != '.')
		return (1);
	*token = lexer(input);
	if (token->type != (t_types){Label}
	|| ft_strcmp(token->str, (i == 0) ? "name" : "comment"))
		return (2);
	return (0);
}

int				parse_header(int input, int output, t_token *token, int *value)
{
	unsigned int		i;

	i = COREWAR_EXEC_MAGIC;
	fixed_write(output, &i, sizeof(i));
	i = 0;
	while (i < 2)
	{
		if (parse_header_arg(input, token, i))
			return (1);
		while ((*token = lexer(input)).type == (t_types){Whitespace})
			;
		if (token->type != (t_types){String})
			return (3);
		if (!i && ft_strlen(token->str) > PROG_NAME_LENGTH)
			return (4);
		else if (i)
			fixed_write(output, value, sizeof(i));
		write(output, token->str, i == 0 ?
		PROG_NAME_LENGTH + 4 : COMMENT_LENGTH + 4);
		while ((*token = lexer(input)).type != (t_types){Newline})
			if (token->type != (t_types){Whitespace})
				return (4);
		i++;
	}
	return (0);
}

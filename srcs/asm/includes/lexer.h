/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:06:09 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:06:11 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define WHITESPACE_CHARS		"\t\n\v\f\r "
# define SYMBOL_CHARS			"#:%,.-+"
# define COMMENT_CHAR_2			';'

typedef enum		e_types
{
	Unknown = -1,
	None = 0,
	Comment,
	Whitespace,
	Newline,
	Label,
	Keyword,
	Register,
	Symbol,
	String,
	Number
}					t_types;

typedef struct		s_token
{
	char			str[COMMENT_LENGTH + 1];
	t_types			type;
	int				col;
	int				line;
}					t_token;

t_token				lexer(int fd);

#endif

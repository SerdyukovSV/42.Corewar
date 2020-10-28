/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:06:29 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:06:30 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct		s_arg
{
	char			type;
	int				value;
	int				size;
}					t_arg;

int					parse_header(int in, int out, t_token *token, int *value);
int					parse_opcode(int in, int out, t_token *token, int opcode);

int					ft_compile(char *input_name, char *output_name);

#endif

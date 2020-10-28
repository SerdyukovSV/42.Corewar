/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:06:03 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:06:05 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

# include "lexer.h"

typedef struct		s_label
{
	int				index;
	t_list			*label;
}					t_label;

t_label				*getlabels(void);
t_label				*getlabels_use(void);

int					label_index(char *name);
int					label_value(char *name, int index);
int					add_label(char *name, int value);

int					skip_header(int input, t_token *token);
int					peek_opcode(int input, int *value, t_token *token, int op);

int					init_label(int input, int *value);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:06:34 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:06:35 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include <stdlib.h>

# include "lexer.h"

typedef struct		s_char
{
	char			c;
	int				col;
	int				line;
}					t_char;

int					lexical_error(t_token token, int ft_errnum);
void				ft_delete_label(void *content, size_t size);

t_char				scanner(int fd);

#endif

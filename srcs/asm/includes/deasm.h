/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deasm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:05:19 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:05:23 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEASM_H
# define DEASM_H

# include "libft.h"

int		ft_decompile(char *input_name, char *output_name);
int		rev_parser_manage_octal(int input, int output, unsigned int opcode);
int		rev_parser_manage_other(int input, int output, unsigned int opcode);

#endif

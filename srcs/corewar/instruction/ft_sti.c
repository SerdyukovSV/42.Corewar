/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:00:55 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/07 21:01:02 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_sti(t_vm *vm, t_cursor *cursor)
{
	int value_1;
	int value_2;
	int addres;
	int id;

	id = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
	value_1 = get_arg_instr(vm, cursor, cursor->args_type[1], ON);
	value_2 = get_arg_instr(vm, cursor, cursor->args_type[2], ON);
	if (cursor->args_type[1] & T_REG && is_register(value_1))
		value_1 = cursor->reg[value_1 - 1];
	if (cursor->args_type[2] & T_REG && is_register(value_2))
		value_2 = cursor->reg[value_2 - 1];
	if (is_register(id))
	{
		addres = cursor->pc + MODX((value_1 + value_2));
		set_int_by_addres(vm, addres, cursor->reg[id - 1], REG_SIZE);
	}
}

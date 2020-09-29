#include "../../includes/corewar.h"

void    ft_sti(t_vm *vm, t_cursor *cursor)
{
    int value_1;
    int value_2;
    int addres;
    int id;

    cursor->step += OPC_LEN;
    cursor->step += cursor->op->args_type_code;
    id = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    value_1 = get_arg_instr(vm, cursor, cursor->args_type[1], ON);
    value_2 = get_arg_instr(vm, cursor, cursor->args_type[2], ON);
    if (cursor->args_type[1] & T_REG && is_register(value_1))
        value_1 = cursor->reg[value_1];
    if (cursor->args_type[2] & T_REG && is_register(value_2))
        value_2 = cursor->reg[value_2];
    if (is_register(id))
    {
        addres = cursor->pc + MODX((value_1 + value_2));
        set_value_by_addres(vm, addres, cursor->reg[id], REG_SIZE);
    }

}
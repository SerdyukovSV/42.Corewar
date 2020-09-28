#include "../../includes/corewar.h"

void    ft_or(t_vm *vm, t_cursor *cursor)
{
    int val_1;
    int val_2;
    int id;

    cursor->step += OPC_LEN;
    cursor->step += cursor->op->args_type_code;
    val_1 = get_arg_instr(vm, cursor, cursor->args_type[0], ON);
    val_2 = get_arg_instr(vm, cursor, cursor->args_type[1], ON);
    if (cursor->args_type[0] & T_REG && is_register(val_1))
        val_1 = cursor->reg[val_1 - 1];
    if (cursor->args_type[1] & T_REG && is_register(val_2))
        val_2 = cursor->reg[val_2 - 1];
    id = get_arg_instr(vm, cursor, cursor->args_type[2], OFF);
    if (is_register(id))
    {
        cursor->reg[id - 1] = val_1 | val_2;
        cursor->carry = (val_1 | val_2) ? 0 : 1;
    }
}
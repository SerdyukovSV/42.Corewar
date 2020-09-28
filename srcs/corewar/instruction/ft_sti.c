#include "../../includes/corewar.h"

void    ft_sti(t_vm *vm, t_cursor *cursor)
{
    int value_1;
    int value_2;
    // int     value;
    int     id;

    cursor->step += OPC_LEN;
    cursor->step += cursor->op->args_type_code;
    id = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    value_1 = get_arg_instr(vm, cursor, cursor->args_type[1], ON);
    value_2 = get_arg_instr(vm, cursor, cursor->args_type[2], ON);
    // if (cursor->args_type[1] & T_REG && is_register(value_1))
        // value_1 = cursor->reg[value_1];
}
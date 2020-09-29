#include "../../includes/corewar.h"

void    ft_lld(t_vm *vm, t_cursor *cursor)
{
    int value;
    int id;

    value = 0;
    cursor->step += OPC_LEN;
    cursor->step += cursor->op->args_type_code;
    value = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    cursor->carry = (value == 0) ? 1 : 0;
    id = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
    if (is_register(id))
        cursor->reg[id - 1] = value;
}
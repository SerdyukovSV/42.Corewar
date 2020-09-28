#include "../../includes/corewar.h"

void    ft_add(t_vm *vm, t_cursor *cursor)
{
    int8_t  id[3];
    int     sum;

    sum = 0;
    cursor->step += OPC_LEN;
    cursor->step += cursor->op->args_type_code;
    id[0] = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    id[1] = get_arg_instr(vm, cursor, cursor->args_type[1], OFF);
    if (is_register(id[0]) && is_register(id[1]))
    {
        sum = cursor->reg[id[0] - 1] + cursor->reg[id[1] - 1];
        id[2] = get_arg_instr(vm, cursor, cursor->args_type[2], OFF);
        if (is_register(id[2]))
            cursor->reg[id[2] - 1] = sum;
        cursor->carry = sum ? 0 : 1;
    }
}
#include "../../includes/corewar.h"

void    ft_zjmp(t_vm *vm, t_cursor *cursor)
{
    int16_t addres;

    cursor->step += OPC_LEN;
    addres = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    if (cursor->carry == 1)
    {
        cursor->pc = MODA((cursor->pc + MODX(addres)));
        cursor->step = 0;
    }
}
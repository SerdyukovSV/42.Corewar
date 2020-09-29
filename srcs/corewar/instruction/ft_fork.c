#include "../../includes/corewar.h"

void    ft_fork(t_vm *vm, t_cursor *cursor)
{
    t_cursor    *new_cursor;
    int         addres;

    cursor->step += OPC_LEN;
    addres = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    new_cursor = push_top_cursor(vm);
    copy_cursor(new_cursor, cursor);
    new_cursor->id = vm->cursors_num++;
    new_cursor->pc = MODA((cursor->pc + MODX(addres)));
}
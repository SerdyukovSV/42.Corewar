#include "../../includes/corewar.h"

void    exec_instr(t_vm *vm, t_cursor *cursor)
{
    if (cursor->cycles_to_exec == 0)
        get_operation(vm, cursor);
    else if (cursor->cycles_to_exec > 0)
        cursor->cycles_to_exec--;
    if (cursor->cycles_to_exec == 0)
    {
    }
}

void    move_cursor(t_vm *vm)
{
    t_cursor *cursor;

    cursor = vm->cursor;
    while (cursor)
    {
        exec_instr(vm, cursor);
        cursor = cursor->next;
    }
}

void    cw_to_playing(t_vm *vm)
{
    while (vm->cursor)
    {
        if (vm->dump == vm->total_cycles)
            ;
        move_cursor(vm);
        if (vm->cycles_to_check == vm->cycles_to_die || vm->cycles_to_die <= 0)
            ;
        vm->total_cycles++;
        vm->cycles_to_check++;
    }
}
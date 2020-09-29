#include "../../includes/corewar.h"

static int  is_check_cycle(t_vm *vm)
{
    return (vm->cycles_to_check == vm->cycles_to_die || \
            vm->cycles_to_die <= 0);
}

static void execute_instruction(t_vm *vm, t_cursor *cursor)
{
    if (cursor->cycles_to_exec == 0)
        get_operation(vm, cursor);
    else if (cursor->cycles_to_exec > 0)
        cursor->cycles_to_exec--;
    if (cursor->cycles_to_exec == 0)
    {
        if (cursor->op)
        {
            parse_args_byte_code(vm, cursor);
            if (!validate_instr(vm, cursor))
                cursor->op->func(vm, cursor);
            else
                cursor->step += get_all_steps(cursor);
        }
        else
            cursor->step++;
        move_cursor(cursor);
    }
}

static void execute_cursors(t_vm *vm)
{
    t_cursor *cursor;

    cursor = vm->cursor;
    while (cursor)
    {
        execute_instruction(vm, cursor);
        cursor = cursor->next;
    }
}

void        play_corewar(t_vm *vm)
{
    while (vm->cursor)
    {
        if (vm->dump == vm->total_cycles)
            ;
        execute_cursors(vm);
        if (is_check_cycle(vm))
            check_cycle(vm);
        vm->total_cycles++;
        vm->cycles_to_check++;
    }
}
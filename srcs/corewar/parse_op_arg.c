#include "../../includes/corewar.h"

int set_type_arg()
{}

int get_abc(t_cursor *cursor, uint8_t byte)
{
    // if (((byte & 0xC0) >> 6) & )
}

int parse_op_args(t_vm *vm, t_cursor *cursor)
{
    int pc;

    pc = cursor->pc;
    if (vm->op_tab[cursor->op_code - 1].args_type_code == 1)
    {
        get_abc(cursor, get_byte(vm, cursor->pc + 1));
        cursor->step += 1;
    }
}
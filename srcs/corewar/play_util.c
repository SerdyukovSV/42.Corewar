#include "../../includes/corewar.h"

static int  is_operation(int value)
{
    return (value >= 0x01 && value <= 0x10);
}

int8_t      get_byte(t_vm *vm, int index)
{
    return (vm->arena[MODA(index)]);
}

int         get_operation(t_vm *vm, t_cursor *cursor)
{
    int code;

    code = get_byte(vm, cursor->pc);
    if (is_operation(code))
    {
        cursor->op_code = code;
        cursor->cycles_to_exec = vm->op_tab[code - 1].cycles;
        return (code);
    }
    return (0);
}
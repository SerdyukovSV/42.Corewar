#include "../../includes/corewar.h"

int         get_step(t_op *operation, int type_arg)
{
    if (type_arg & T_REG)
        return (1);
    else if (type_arg & T_IND)
        return (IND_SIZE);
    else if (type_arg & T_DIR)
        return (operation->t_dir_size);
}

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

    cursor->operation = NULL;
    code = get_byte(vm, cursor->pc);
    if (is_operation(code))
    {
        cursor->op_code = code;
        cursor->operation = &vm->op_tab[code - 1];
        cursor->cycles_to_exec = cursor->operation->cycles;
        return (code);
    }
    return (0);
}
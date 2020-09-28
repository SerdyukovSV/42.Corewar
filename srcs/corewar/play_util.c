#include "../../includes/corewar.h"

static int  is_operation(int op_code)
{
    return (op_code >= 0x01 && op_code <= 0x10);
}

int         is_register(int reg_id)
{
    return (reg_id >= 0x01 && reg_id <= 0x10);
}

int8_t      get_byte(t_vm *vm, int index)
{
    return (vm->arena[MODA(index)]);
}

int         get_step(t_op *operation, int type_arg)
{
    if (type_arg & T_REG)
        return (1);
    else if (type_arg & T_IND)
        return (IND_SIZE);
    else if (type_arg & T_DIR)
        return (operation->t_dir_size);
}

int         get_operation(t_vm *vm, t_cursor *cursor)
{
    int code;

    cursor->op = NULL;
    code = get_byte(vm, cursor->pc);
    if (is_operation(code))
    {
        cursor->op_code = code;
        cursor->op = &vm->op_tab[code - 1];
        cursor->cycles_to_exec = cursor->op->cycles;
        return (code);
    }
    return (0);
}
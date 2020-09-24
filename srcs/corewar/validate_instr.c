#include "../../includes/corewar.h"

static int  check_args_types(t_vm *vm, t_cursor *cursor)
{
    int i;

    i = 0;
    while (i < cursor->operation->args_num)
    {
        if (!(cursor->args_type[i] & cursor->operation->args_type[i]))
            return (ERRABC);
        i++;
    }
}

static int  check_args(t_vm *vm, t_cursor *cursor)
{
    int value;
    int step;
    int i;

    i = 0;
    step = cursor->step;
    while (i < cursor->operation->args_num)
    {
        if (cursor->args_type[i] & T_REG)
        {
            value = get_byte(vm, step + 1);
            if (!(value >= 0x01 && value <= 0x10))
                return (ERRARG);
        }
        step += get_step(cursor->operation, cursor->args_type[i]);
    }
}

int         validate_instr(t_vm *vm, t_cursor *cursor)
{
    return (check_args(vm, cursor) | check_args_types(vm, cursor));
}
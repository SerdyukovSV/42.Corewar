#include "../../includes/corewar.h"

static void set_type_args(t_cursor *cursor, uint8_t args_byte_code)
{
    uint8_t abc;
    int     i;

    i = 0;
    abc = args_byte_code;
    while (i < cursor->op->args_num)
    {
        if (i == 0)
            cursor->args_type[i] = FT_BIT(((abc & 0xC0) >> 6));
        else if (i == 1)
            cursor->args_type[i] = FT_BIT(((abc & 0x30) >> 4));
        else if (i == 2)
            cursor->args_type[i] = FT_BIT(((abc & 0x0C) >> 2));
        i++;
    }
}

void        parse_args_byte_code(t_vm *vm, t_cursor *cursor)
{
    int code;

    code = cursor->op_code - 1;
    if (cursor->op->args_type_code == 1)
    {
        set_type_args(cursor, get_byte(vm, cursor->pc + 1));
        cursor->step += 1;
    }
    else
        cursor->args_type[0] = cursor->op->args_type[0];
}
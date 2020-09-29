#include "../../includes/corewar.h"

void    ft_aff(t_vm *vm, t_cursor *cursor)
{
    char    ch;
    int     id;

    cursor->step += OPC_LEN;
    id = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    if (is_register(id))
    {
        ch = (char)(cursor->reg[id - 1]);
        if (ft_isascii(ch))
            ft_putchar(ch);
    }
}
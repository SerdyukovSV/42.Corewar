#include "../../includes/corewar.h"

int     is_player(int total_player, int id_player)
{
    return (id_player <= -1 && id_player >= -(total_player));
}

void    ft_live(t_vm *vm, t_cursor *cursor)
{
    int value;

    value = 0;
    vm->nbr_live++;
    cursor->step += OPC_LEN;
    cursor->last_live = vm->total_cycles;
    value = get_arg_instr(vm, cursor, cursor->args_type[0], OFF);
    if (is_player(vm->players_num, value))
    {
        value *= -1;
        vm->last_alive = vm->players[value - 1];
    }
}
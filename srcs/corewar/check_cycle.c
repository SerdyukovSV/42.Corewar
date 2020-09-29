#include "../../includes/corewar.h"

int     is_modified_ctd(t_vm *vm)
{
    return (vm->nbr_checks == MAX_CHECKS || vm->nbr_live == NBR_LIVE);
}

int     is_died_cursor(t_vm *vm, t_cursor *cursor)
{
    int last_live;

    last_live = vm->total_cycles - cursor->last_live;
    if (last_live >= vm->cycles_to_die || vm->cycles_to_die <= 0)
        return (1);
    return (0);
}

void    delete_cursor(t_vm *vm)
{
    t_cursor *cursor;
}

void    check_cycle(t_vm *vm)
{
    vm->nbr_checks++;
    delete_cursor(vm);
    if (is_modified_ctd(vm))
    {
        vm->cycles_to_die -= CYCLE_DELTA;
        vm->nbr_checks = 0;
    }
    vm->nbr_live = 0;
    vm->cycles_to_check = 0;
}
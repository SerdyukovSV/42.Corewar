#include "../../includes/corewar.h"

void    delete_cursor(t_vm *vm, int id)
{
    t_cursor *cursor;
    t_cursor *tmp;

    cursor = vm->cursor;
    if (cursor->id == id)
    {
        vm->cursor = vm->cursor->next;
        free(cursor);
    }
    else
    {
        while (cursor->next && cursor->next->id != id)
            cursor = cursor->next;
        if (cursor->next->id == id)
        {
            tmp = cursor->next;
            cursor = cursor->next->next;
            free(tmp);
        }
    }
}

int     modified_ctd(t_vm *vm)
{
    vm->nbr_checks++;
    if (vm->nbr_checks == MAX_CHECKS || vm->nbr_live == NBR_LIVE)
    {
        vm->cycles_to_die -= CYCLE_DELTA;
        vm->nbr_checks = 0;
    }
    vm->nbr_live = 0;
    vm->cycles_to_check = 0;
}

int     is_dead_cursor(t_vm *vm, t_cursor *cursor)
{
    int last_live;

    last_live = vm->total_cycles - cursor->last_live;
    if (last_live >= vm->cycles_to_die || vm->cycles_to_die <= 0)
        return (1);
    return (0);
}

void    check_cursor(t_vm *vm)
{
    t_cursor *cursor;

    cursor = vm->cursor;
    while (cursor)
    {
        if (is_dead_cursor(vm, cursor))
        {
            delete_cursor(vm, cursor->id);
        }
        else
            cursor = cursor->next;
    }
}

void    check_ctd_and_cursor(t_vm *vm)
{
    check_cursor(vm);
    modified_ctd(vm);
}
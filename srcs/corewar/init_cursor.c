#include "../../includes/corewar.h"

void        copy_cursor(t_cursor *dst, t_cursor *src)
{
    dst->carry = src->carry;
    dst->cycles_to_exec = 0;
    dst->last_live = src->last_live;
    dst->op_code = 0;
    ft_memcpy(dst->reg, src->reg, sizeof(int) * REG_NUMBER);
    ft_bzero(dst->args_type, sizeof(int) * 3);
    dst->op = NULL;
    dst->step = 0;
}

void        fill_cursor(t_cursor *new, int addres, int id)
{
    new->carry = 0;
    new->cycles_to_exec = 0;
    new->id = id + 1;
    new->last_live = 0;
    new->op_code = 0;
    new->pc = addres;
    new->op = NULL;
    ft_bzero(new->reg, sizeof(int) * REG_NUMBER);
    ft_bzero(new->args_type, sizeof(int) * 3);
    new->reg[0] = -(id + 1);
    new->step = 0;
}

t_cursor    *push_top_cursor(t_vm *vm)
{
    t_cursor *new_cursor;

    if (!(new_cursor = malloc(sizeof(t_cursor))))
        ft_error(vm, errno);
    new_cursor->next = vm->cursor;
    vm->cursor = new_cursor;
    return (new_cursor);
}

void        init_cursor(t_vm *vm)
{
    t_cursor    *tmp;
    int         i;

    i = 0;
    while (i < vm->players_num)
    {
        tmp = push_top_cursor(vm);
        fill_cursor(tmp, vm->players[i]->location, i);
        vm->cursors_num++;
        i++;
    }
    vm->last_alive = i;
}
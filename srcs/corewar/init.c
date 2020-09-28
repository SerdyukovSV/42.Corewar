#include "../../includes/corewar.h"

t_cursor    *create_cursor(t_vm *vm, int id)
{
    t_cursor *cursor;

    if (!(cursor = malloc(sizeof(t_cursor))))
        ft_error(vm, errno);
    cursor->carry = 0;
    cursor->cycles_to_exec = 0;
    cursor->id = id;
    cursor->last_live = 0;
    cursor->op_code = 0;
    cursor->pc = vm->players[id]->location;
    ft_bzero(cursor->reg, sizeof(int) * REG_NUMBER);
    ft_bzero(cursor->args_type, sizeof(int) * 3);
    cursor->reg[0] = -(id + 1);
    cursor->step = 0;
    cursor->next = NULL;
    return (cursor);
}

void        init_cursor(t_vm *vm)
{
    t_cursor    *tmp;
    int         i;

    i = 0;
    while (vm->players[i])
    {
        tmp = create_cursor(vm, i);
        tmp->next = vm->cursor;
        vm->cursor = tmp;
        i++;
    }
    vm->last_alive = i;
}

void        init_arena(t_vm *vm)
{
    int         location;
    int         i;

    i = 0;
    while (vm->players[i])
    {
        location = MEM_SIZE / vm->players_num * i;
        vm->players[i]->location = location;
        ft_memcpy(vm->arena[location], vm->players[i]->instr,
                                vm->players[i]->isntr_size);
        i++;
    }
}

t_player    *creat_champion(int id)
{
    t_player *player;

    if (!(player = malloc(sizeof(t_player))))
        return (NULL);
    player->id = id;
    player->isntr_size = 0;
    ft_bzero(player->name, sizeof(char) * PROG_NAME_LENGTH);
    ft_bzero(player->comment, sizeof(char) * COMMENT_LENGTH);
    ft_bzero(player->instr, sizeof(char) * CHAMP_MAX_SIZE);
    player->next = NULL;
}

void        init_vm(t_vm *vm)
{
    vm->cursor = NULL;
    vm->cycles_to_die = CYCLE_TO_DIE;
    vm->dump = -1;
    vm->flags = 0;
    vm->id = 0;
    vm->last_alive = NULL;
    vm->nbr_checks = 0;
    vm->nbr_live = 0;
    vm->players_num = 0;
    vm->total_cycles = 0;
    vm->cycles_to_check = 0;
    ft_bzero(vm->arena, sizeof(uint8_t) * MEM_SIZE);
    ft_bzero(vm->players, sizeof(t_player *) * 4);
}
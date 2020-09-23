#include "../../includes/corewar.h"

void        init_arena(t_vm *vm)
{
    int         location;
    int         i;

    i = 0;
    while (i < vm->players_num)
    {
        location = MEM_SIZE / vm->players_num * i;
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
    vm->dump_num = 0;
    vm->flags = 0;
    vm->players_num = 0;
    vm->id = 0;
    ft_bzero(vm->players, sizeof(t_player *) * 4);
}
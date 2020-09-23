#include "../../includes/corewar.h"

static void set_champion_id(t_vm *vm, t_player **lst, t_player *plr)
{
    int i;
    int j;

    j = 0;
    i = 0;
    vm->players[plr->id - 1] = plr;
    while (i < vm->players_num)
    {
        if (vm->players[i] == NULL)
        {
            vm->players[i] = lst[j++];
            vm->players[i]->id = i + 1;
        }
        i++;
    }
}

static void update_champion_id(t_vm *vm)
{
    t_player    *tmp[3];
    t_player    *plr;
    int         i;

    i = 0;
    while (i < vm->players_num)
    {
        if (vm->players[i]->id == 0)
            tmp[i] = vm->players[i];
        else
            plr = vm->players[i];
        vm->players[i] = NULL;
        i++;
    }
    set_champion_id(vm, tmp, plr);
}

void        add_champion(t_vm *vm, t_player *player)
{
    int i;

    i = 0;
    while (i < MAX_PLAYERS)
    {
        if (vm->players[i] == NULL)
        {
            vm->players[i] = player;
            break ;
        }
        i++;
    }
    if (++vm->players_num > MAX_PLAYERS)
        ft_error(vm, 4);
}

static void parse_filename(t_vm *vm, char ***av)
{
    int id;

    if (!ft_strcmp("-n", (*av)[0]))
    {
        if ((id = ft_parse_num(vm, (*av)[1])) && is_extension((*av)[2], EXT))
            ft_parse_champion(vm, (*av)[2], id);
        else
            ft_error(vm, 1);
        (*av) += 3;
        return ;
    }
    else
        ft_parse_champion(vm, (*av)[0], id);
    (*av) += 1;
}

void        ft_parse_args(t_vm *vm, char **argv)
{
    argv++;
    while (*argv)
    {
        if (!ft_strcmp("-dump", argv[0]) && argv[1])
            ft_parse_dump(vm, &argv);
        else if (!ft_strcmp("-n", argv[0]) && argv[2])
            parse_filename(vm, &argv);
        else if (is_extension(argv[0], EXT))
            parse_filename(vm, &argv);
        else
            ft_error(vm, USAGE);
    }
    update_champion_id(vm);
}
#include "../../includes/corewar.h"

int     ft_parse_num(t_vm *vm, char *av)
{
    int id;

    id = 0;
    if (!is_number(av))
        ft_error(vm, 0);
    id = ft_atoi(av);
    if (!(id > 0 && id < 5) || vm->id & FT_BIT(id))
        ft_error(vm, 0);
    vm->id |= FT_BIT(id);
    return (id);
}

void    ft_parse_dump(t_vm *vm, char ***av)
{
    int res;

    res = 0;
    if (!is_number((*av)[1]))
        ft_error(vm, 1);
    if (!(res = ft_atoi((*av)[1])) && ft_strlen((*av)[1]) > 1)
        ft_error(vm, 1);
    vm->flags |= DUMP;
    vm->dump_num = res;
    (*av) += 2;
}
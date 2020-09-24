#include "../../includes/corewar.h"

int main(int argc, char **argv)
{
    t_vm vm;

    if (argc < 2)
        print_usage();
    init_vm(&vm);
    set_op_tab(&vm);
    ft_parse_args(&vm, argv);
    init_arena(&vm);
    init_cursor(&vm);
    intro_player(&vm);

    return (EXIT_SUCCESS);
}
#include "../../includes/corewar.h"

int main(int argc, char **argv)
{
    t_vm vm;

    if (argc < 2)
        print_usage();
    init_vm(&vm);
    ft_parse_args(&vm, argv);
    init_arena(&vm);

    return (EXIT_SUCCESS);
}
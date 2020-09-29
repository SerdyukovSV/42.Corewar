#include "../../includes/corewar.h"

void	intro_player(t_vm *vm)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (vm->players[i])
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\")\n", \
				vm->players[i]->id, vm->players[i]->isntr_size, \
				vm->players[i]->name, vm->players[i]->comment);
		i++;
	}
}

int		print_usage()
{
	ft_printf("\e[1mUsage:\e[0m\n");
	ft_printf("%s [-h] [-dump] [-n] file_champion.core\n", "./corewar");
	ft_printf("\e[1mFlags:\e[0m\n");
	ft_printf("   -h 	: To read the manual.\n");
	ft_printf("   -dump : Dump the memory on the standard output.\n");
	ft_printf("   -n 	: Set champion id number.\n");
	return (0);
}
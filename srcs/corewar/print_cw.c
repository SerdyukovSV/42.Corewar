#include "../../includes/corewar.h"

int			print_usage()
{
	ft_printf("\e[1mUsage:\e[0m\n");
	ft_printf("%s [-h] [-dump] [-n] file_champion.core\n", "./corewar");
	ft_printf("\e[1mFlags:\e[0m\n");
	ft_printf("   -h 	: To read the manual.\n");
	ft_printf("   -dump : Dump the memory on the standard output.\n");
	ft_printf("   -n 	: Set champion id number.\n");
	return (0);
}
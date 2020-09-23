#include "../../includes/corewar.h"

static char	*error[] = {
	[0] = "ERROR: Wrong number argument",
	[1] = "ERROR: Invalid file champion",
	[2] = "ERROR: No null control bytes",
	[3] = "ERROR: Wrong instruction size",
	[4] = "ERROR: Too many champions"
		
};

void		ft_error(t_vm *vm, int code)
{
	// lemin_free(lemin);
	if (code == USAGE)
		print_usage();
	else if (errno == 0)
		ft_putendl_fd(error[code], STDERR_FILENO);
	else
		perror("ERROR");
	exit(EXIT_FAILURE);
}
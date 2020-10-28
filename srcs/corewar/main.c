/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:02:52 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/24 14:02:55 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int	main(int argc, char **argv)
{
	t_vm vm;

	if (argc < 2)
		ft_exit(NULL, USAGE);
	init_vm(&vm);
	set_op_tab(&vm);
	ft_parse_args(&vm, argv);
	init_arena(&vm);
	init_cursor(&vm);
	intro_player(&vm);
	play_corewar(&vm);
	endwin();
	print_winner(&vm);
	ft_free(&vm);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:05:46 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:05:48 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FCT_TAB_H
# define FT_FCT_TAB_H
# include "ft_printf.h"

t_fct		g_fct_tab[] =
{
	{'s', &print_str},
	{'S', &print_str},
	{'p', &print_ptr},
	{'d', &print_int},
	{'D', &print_int},
	{'b', &print_bin},
	{'B', &print_bin},
	{'i', &print_int},
	{'o', &print_oct},
	{'O', &print_oct},
	{'u', &print_uns_int},
	{'U', &print_uns_int},
	{'x', &print_hex},
	{'X', &print_hex},
	{'c', &print_char},
	{'C', &print_char},
	{'n', &get_len},
	{0, NULL}
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:08:39 by gartanis          #+#    #+#             */
/*   Updated: 2020/10/24 14:08:43 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_extension(char *av, char *ext)
{
	char *tmp;

	tmp = ft_strchr(av, '\0');
	if (!ft_strcmp(tmp - 4, ext))
		return (1);
	return (0);
}

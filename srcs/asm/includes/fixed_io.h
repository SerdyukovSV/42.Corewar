/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:05:32 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:05:37 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_IO_H
# define FIXED_IO_H

# include "libft.h"

ssize_t				fixed_write(int fildes, const void *buf, size_t nbyte);
unsigned int		fixed_read_32(int fildes);
unsigned short		fixed_read_16(int fildes);

#endif

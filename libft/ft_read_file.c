/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:13:26 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:08:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_read_file(int fd, long long offset, long long size)
{
	void		*reserved;
	long long	cycle;

	cycle = 0;
	reserved = (void*)ft_memalloc(size);
	if (reserved)
	{
		lseek(fd, offset, SEEK_SET);
		while (size)
		{
			if (size > 512)
			{
				read(fd, reserved + (512 * cycle), 512);
				size -= 512;
			}
			else if (size <= 512)
			{
				read(fd, reserved + (512 * cycle), size);
				size -= size;
			}
			++cycle;
		}
	}
	return (reserved);
}

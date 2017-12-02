/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:03:33 by adaly             #+#    #+#             */
/*   Updated: 2017/05/18 15:32:05 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_shift_data(long long fd, long long offset, \
						long long size, long long shift)
{
	long long	temp;
	void		*buff;

	temp = 0;
	temp = offset;
	buff = ft_memalloc(1024);
	lseek(fd, offset + size, SEEK_SET);
	while (temp > 0)
	{
		ft_bzero(buff, 1024);
		if (temp <= 1024)
		{
			lseek(fd, (-1 * temp), SEEK_CUR);
			read(fd, buff, temp);
			lseek(fd, shift, SEEK_CUR);
			temp -= write(fd, buff, temp);
		}
		else if (temp > 1024)
		{
			lseek(fd, -1024, SEEK_CUR);
			read(fd, buff, 1024);
			lseek(fd, shift, SEEK_CUR);
			temp -= write(fd, buff, 1024);
		}
	}
}

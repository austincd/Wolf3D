/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:47:04 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 19:27:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_make_room(long long fd, long long to_add, long long offset)
{
	long long	temp;
	long long	original_size;
	void		*empty;
	int			status;

	original_size = 0;
	status = 0;
	temp = to_add;
	while ((status = read(fd, NULL, 1024)))
		original_size += status;
	while (temp > 0)
	{
		if (temp <= 1024)
			temp -= write(fd, empty, temp);
		else if (temp > 1024)
			temp -= write(fd, empty, 1024);
	}
	ft_shift_data(fd, offset, original_size, to_add);
}
